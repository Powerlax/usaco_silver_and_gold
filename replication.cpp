//
// Created by innav_z3e3dq9 on 11/17/2024.
//

#include <bits/stdc++.h>
using namespace std;

struct State {
    int x, y, distance;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, d;
    cin >> n >> d;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    vector rock_dist(n, vector(n, -1));
    queue<State> frontier;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '#') {
                frontier.push({i, j, 0});
            }
        }
    }
    while (!frontier.empty()) {
        const auto [x, y, distance] = frontier.front();
        frontier.pop();
        if (x < 0 || x >= n || y < 0 || y >= n || rock_dist[x][y] != -1) {
            continue;
        }
        rock_dist[x][y] = distance;
        for (int i = -1; i <= 1; i += 2) {
            frontier.push({x + i, y, distance + 1});
            frontier.push({x, y + i, distance + 1});
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'S') {
                frontier.push({i, j, 0});
            }
        }
    }
    vector visited(n, vector(n, -1));
    while (!frontier.empty()) {
        const auto [x, y, distance] = frontier.front();
        frontier.pop();
        int size = (distance - 1) / d;
        if (x < 0 || x >= n || y < 0 || y >= n || visited[x][y] != -1 || rock_dist[x][y] <= size) {
            continue;
        }
        visited[x][y] = size;
        size = distance / d;
        if (rock_dist[x][y] <= size) {
            continue;
        }
        visited[x][y] = size;
        for (int i = -1; i <= 1; i += 2) {
            frontier.push({x + i, y, distance + 1});
            frontier.push({x, y + i, distance + 1});
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k <= visited[i][j]; k++) {
                for (int l = 0; l <= visited[i][j] - k; l++) {
                    grid[i + k][j + l] = 'X';
                    grid[i - k][j + l] = 'X';
                    grid[i + k][j - l] = 'X';
                    grid[i - k][j - l] = 'X';
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans += (grid[i][j] == 'X' ? 1 : 0);
        }
    }
    cout << ans << endl;
    return 0;
}