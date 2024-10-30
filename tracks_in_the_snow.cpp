//
// Created by innav_z3e3dq9 on 10/29/2024.
//

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> snow;

bool within_bounds(const int x, const int y) {
    return (x > -1 && x < n && y > -1 && y < m && snow[x][y] != '.');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> snow[i];
    }
    snow.resize(n);
    deque<pair<int, int>> q;
    q.emplace_back(0, 0);
    vector depth(n, vector<int>(m));
    depth[0][0] = 1;
    vector dx({1, -1, 0, 0}), dy({0, 0, 1, -1});
    int ans = 1;
    while (!q.empty()) {
        auto [a, b] = q.front();
        q.pop_front();
        ans = max(ans, depth[a][b]);
        for (int i = 0; i < 4; i++) {
            int y = b + dy[i];
            if (int x = a + dx[i]; within_bounds(x, y) && depth[x][y] == 0) {
                if (snow[x][y] == snow[a][b]) {
                    depth[x][y] = depth[a][b];
                    q.emplace_front(x, y);
                } else {
                    depth[x][y] = depth[a][b] + 1;
                    q.emplace_back(x, y);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}