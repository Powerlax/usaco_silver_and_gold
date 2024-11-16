//
// Created by innav_z3e3dq9 on 8/5/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("revegetate.in", "r", stdin);
    //freopen("revegetate.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, bool>>> adj(n);
    for (int i = 0; i < m; i++) {
        char c;
        int a, b;
        cin >> c >> a >> b;
        a--;
        b--;
        bool d = c == 'S';
        adj[a].emplace_back(b, d);
        adj[b].emplace_back(a, d);
    }
    int ans = 0;
    bool impossible = false;
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            ans++;
            queue<pair<int, bool>> todo;
            todo.emplace(i, true);
            while (!todo.empty()) {
                pair<int, bool> nxt = todo.front();
                todo.pop();
                color[nxt.first] = nxt.second;
                for (pair<int, bool> u : adj[nxt.first]) {
                    bool type = u.second == nxt.second;
                    if (color[u.first] == -1) {
                        todo.emplace(u.first, type);
                    } else if (color[u.first] == !type) {
                        impossible = true;
                        break;
                    }
                }
            }
        }
    }
    if (impossible) {
        cout << 0 << endl;
    } else {
        cout << 1;
        for (int i = 0; i < ans; i++) { cout << 0; }
        cout << endl;
    }
}