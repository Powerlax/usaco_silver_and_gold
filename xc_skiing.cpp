//
// Created by innav_z3e3dq9 on 8/7/2024.
//

#include <bits/stdc++.h>
using namespace std;

int n, m, points_reached, points_needed;
vector<vector<int>> grid;
vector<vector<bool>> check;
vector<vector<bool>> visited;

int first_true(int lo, int hi, function<bool(int)> f) {
    hi++;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (f(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

void floodfill(int r, int c, int d, int old_height) {
    if (points_reached == points_needed) {
        return;
    }
    if (r < 0 || r >= n || c < 0 || c >= m) {
        return;
    }
    if (visited[r][c]) {
        return;
    }
    if (abs(old_height - grid[r][c]) > d) {
        return;
    }
    if (check[r][c]) {
        points_reached++;
    }
    visited[r][c] = true;
    floodfill(r+1, c, d, grid[r][c]);
    floodfill(r-1, c, d, grid[r][c]);
    floodfill(r, c+1, d, grid[r][c]);
    floodfill(r, c-1, d, grid[r][c]);
}

int main() {
    freopen("ccski.in", "r", stdin);
    freopen("ccski.out", "w", stdout);
    cin >> n >> m;
    grid = vector<vector<int>>(n);
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            int temp;
            cin >> temp;
            grid[i].push_back(temp);
        }
    }
    check = vector<vector<bool>>(n);
    points_needed = 0;
    bool found = false;
    int x, y;
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            int temp;
            cin >> temp;
            check[i].push_back(temp == 1);
            if (temp == 1) {
                points_needed++;
                if (!found) {
                    x = i;
                    y = j;
                    found = true;
                }
            }
        }
    }
    cout << first_true(0, 1000000001, [&](int d) {
        visited = vector<vector<bool>>(n, vector<bool>(m));
        points_reached = 0;
        floodfill(x, y, d, grid[x][y]);
        return points_needed == points_reached;
    });
    return 0;
}