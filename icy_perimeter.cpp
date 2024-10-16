//
// Created by innav_z3e3dq9 on 8/6/2024.
//

#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> grid;
vector<vector<bool>> visited;
int n, curr = 0, ans = 0;

void floodfill(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= n) {
        curr++;
        return;
    }
    if (visited[r][c]) {
        return;
    }
    if (!grid[r][c]) {
        curr++;
        return;
    }
    visited[r][c] = true;
    ans++;
    floodfill(r+1, c);
    floodfill(r-1, c);
    floodfill(r, c+1);
    floodfill(r, c-1);
}

int main() {
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    cin >> n;
    grid = vector<vector<bool>>(n);
    for (int i = 0; i<n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j<n; j++) {
            grid[i].push_back(s[j]=='#');
        }
    }
    visited = vector<vector<bool>>(n, vector<bool>(n));
    int area = 0, perimeter = INT_MAX;
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            if (grid[i][j] && !visited[i][j]) {
                curr = 0, ans = 0;
                floodfill(i, j);
                if (ans > area || (ans == area && curr < perimeter)) {
                    area = ans;
                    perimeter = curr;
                }
            }
        }
    }
    cout << area << " " << perimeter << endl;
    return 0;
}