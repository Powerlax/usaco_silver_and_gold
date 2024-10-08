//
// Created by innav_z3e3dq9 on 8/6/2024.
//

#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> grid;
vector<vector<bool>> visited;
int n, m;

void floodfill(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= m) {
        return;
    }
    if (!grid[r][c]) {
        return;
    }
    if (visited[r][c]) {
        return;
    }
    visited[r][c] = true;
    floodfill(r+1, c);
    floodfill(r-1, c);
    floodfill(r, c+1);
    floodfill(r, c-1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    grid = vector<vector<bool>>(n);
    for (int i = 0; i<n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j<m; j++) {
            grid[i].push_back(s[j]=='.');
        }
    }
    int ans = 0;
    visited = vector<vector<bool>>(n, vector<bool>(m));
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            if (grid[i][j] && !visited[i][j]) {
                floodfill(i, j);
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}