//
// Created by innav_z3e3dq9 on 12/14/2024.
//
#include <bits/stdc++.h>
using namespace std;

int n;
string options = "LRUD";
map<char, pair<int, int>> movement;

bool dfs(int x, int y, vector<vector<bool>> &visited, vector<vector<char>> &grid) {
    if (x < 0 || x >= n || y < 0 || y >= n) {
        return true;
    }
    if (visited[x][y] == true) {
        return false;
    }
    visited[x][y] = true;
    if (grid[x][y] != '?') {
        auto [i, j] = movement[grid[x][y]];
        if (dfs(x+i, y+j, visited, grid)) {
            visited[x][y] = false;
            return true;
        }
        return false;
    }
    for (char option : options) {
        grid[x][y] = option;
        auto [i, j] = movement[grid[x][y]];
        if (dfs(x+i, y+j, visited, grid)) {
            return true;
        }
    }
    visited[x][y] = false;
    grid[x][y] = '?';
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    movement['L'] = make_pair(0, -1);
    movement['R'] = make_pair(0, 1);
    movement['U'] = make_pair(1, 0);
    movement['D'] = make_pair(-1, 0);
    int q;
    cin >> n >> q;
    vector real(n, vector(q, '?'));
    while (q--) {
        int x, y;
        char move;
        cin >> x >> y >> move;
        real[x - 1][y - 1] = move;
        vector<vector<char>> grid = real;
        vector<vector<bool>> visited(n, vector(n, false));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans += (dfs(i, j, visited, grid) ? 0 : 1);
            }
        }
        cout << ans << endl;
    }
}