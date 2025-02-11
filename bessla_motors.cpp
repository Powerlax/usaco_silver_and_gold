//
// Created by innav_z3e3dq9 on 2/8/2025.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, c, r, k;
    cin >> n >> m >> c >> r >> k;
    vector<tuple<int, int, int>> adj(m*2);
    for (int i = 0; i < m * 2; i += 2) {
        int u, v, l;
        cin >> u >> v >> l;
        u--;
        v--;
        adj[i] = make_tuple(u, v, l);
        adj[i + 1] = make_tuple(v, u, l);
    }
    vector<int> ans;
    for (int i = c; i < n; i++) {
        unordered_set<int> s;
        vector<long long> dists(n, INT_MAX);
        dists[i] = 0;
        bool ok = false;
        for (int j = 0; j < n - 1; j++) {
            for (const auto e : adj) {
                int u, v, l;
                tie(u, v, l) = e;
                dists[v] = min(dists[v], dists[u] + l);
                if (dists[v] <= r && v < c) {
                    s.insert(v);
                }
            }
            if (s.size() >= k) {
                ok = true;
                break;
            }
        }
        if (ok) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] + 1 << endl;
    }
    return 0;
}