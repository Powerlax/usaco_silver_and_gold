//
// Created by innav_z3e3dq9 on 11/21/2024.
//

#include <bits/stdc++.h>
using namespace std;

struct Path {
    int x, y, num_fields;
    long long time;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen("visitfj.in", "r", stdin);
    //freopen("visitfj.out", "w", stdout);
    int n, t;
    cin >> n >> t;
    vector grid(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    vector visited(n, vector<bool>(n));
    queue<Path> frontier;
    frontier.push({0, 0, -1, -grid[0][0]});
    long long ans = LLONG_MAX;
    vector<pair<int, int>> movement = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    while (!frontier.empty()) {
        auto node = frontier.front();
        frontier.pop();
        visited[node.x][node.y] = true;
        node.num_fields++;
        if (node.num_fields % 3 == 0) {
            node.time += grid[node.x][node.y];
        }
        if (node.x == n - 1 && node.y == n - 1) {
            ans = min(ans, node.time);
            continue;
        }
        for (const auto [i, j] : movement) {
            if (node.x + i < 0 || node.x + i >= n || node.y + j < 0 || node.y + j >= n) {
                continue;
            }
            if (!visited[node.x + i][node.y + j]) {
                auto next = node;
                next.x = node.x + i;
                next.y = node.y + j;
                next.time += t;
                frontier.push(next);
            }
        }
    }
    cout << ans << endl;
    return 0;
}