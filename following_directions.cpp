//
// Created by innav_z3e3dq9 on 9/2/2024.
//

#include <bits/stdc++.h>
using namespace std;

struct Cell {
    bool is_vat;
    int cost;
    char dir;
    int pass_through;
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<vector<Cell>> grid(n+1);
    for (int i = 0; i < n; i++) {
        string s;
        int c;
        cin >> s >> c;
        for (int j = 0; j<n; j++) {
            grid[i].push_back({false, -1, s[j], 1});
        }
        grid[i].push_back({true, c, 'N', 0});
    }
    for (int i = 0; i<n; i++) {
        int c;
        cin >> c;
        grid[n].push_back({true, c, 'N', 0});
    }
    int q;
    cin >> q;
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            if (grid[i][j].dir == 'R') {
                grid[i][j+1].pass_through += grid[i][j].pass_through;
            } else {
                grid[i+1][j].pass_through += grid[i][j].pass_through;
            }
        }
    }
    for (int i = 0; i<q+1; i++) {
        int ans = 0;
        for (int j = 0; j<n; j++) {
            ans += grid[j][n].cost * grid[j][n].pass_through;
        }
        for (int j = 0; j<n; j++) {
            ans += grid[n][j].cost * grid[n][j].pass_through;
        }
        cout << ans << endl;
        if (i == q) {
            break;
        }
        int r, c;
        cin >> r >> c;
        r--;
        c--;
        int x = r, y = c;
        if (grid[r][c].dir == 'R') {
            y++;
            grid[r][c].dir = 'D';
        } else {
            x++;
            grid[r][c].dir = 'R';
        }
        while (true) {
            grid[x][y].pass_through -= grid[r][c].pass_through;
            if (grid[x][y].is_vat) {
                break;
            }
            if (grid[x][y].dir == 'R') {
                y++;
            } else {
                x++;
            }
        }
        x = r, y = c;
        if (grid[x][y].dir == 'R') {
            y++;
        } else {
            x++;
        }
        while (true) {
            grid[x][y].pass_through += grid[r][c].pass_through;
            if (grid[x][y].is_vat) {
                break;
            }
            if (grid[x][y].dir == 'R') {
                y++;
            } else {
                x++;
            }
        }
    }
    return 0;
}