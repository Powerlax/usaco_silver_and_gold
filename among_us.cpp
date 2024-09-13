//
// Created by innav_z3e3dq9 on 8/6/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int n;
        int q;
        cin >> n >> q;
        vector<vector<pair<int, bool>>> adj(n);
        for (int i = 0; i < q; i++) {
            int type;
            int x;
            int y;
            cin >> type >> x >> y;
            --x;
            --y;
            --type;
            adj[x].push_back({y, type});
            adj[y].push_back({x, type});
        }
        vector<int> role(n, -1);
        int ans = 0;
        bool impossible = false;
        for (int i = 0; i < n; i++) {
            if (role[i] == -1) {
                int imposters = 0, crewmates = 0;
                stack<int> todo;
                todo.push(i);
                role[i] = true;
                imposters++;
                while (!todo.empty()) {
                    int curr = todo.top();
                    todo.pop();
                    for (pair<int, bool> u : adj[curr]) {
                        bool type = u.second ? role[curr] : !role[curr];
                        if (role[u.first] == -1) {
                            role[u.first] = type;
                            if (type) {
                                imposters++;
                            } else {
                                crewmates++;
                            }
                            todo.push(u.first);
                        } else if (role[u.first] == !type) {
                            impossible = true;
                            break;
                        }
                    }
                }
                ans += max(imposters, crewmates);
            }
        }
        cout << (impossible ? -1 : ans) << endl;
    }
}