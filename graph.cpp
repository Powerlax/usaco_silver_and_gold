//
// Created by innav_z3e3dq9 on 8/12/2024.
//
#include <bits/stdc++.h>
using namespace std;

long long val = 1e18;
const long long emp = 1e18;
bool bad = false;

pair<long long, long long> operator+(pair<long long, long long> a, pair<long long, long long> b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

int main() {
    long long n, m;
    cin >> n >> m;
    vector<vector<pair<long long, long long>>> adj(n);
    vector<vector<long long>> conn_comps;
    vector<bool> vis(n);
    for (long long i = 0; i < m; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    vector<pair<long long, long long>> coeffs(n, make_pair(-1e18, -1e18));
    function<void(long long)> dfs = [&](long long u) {
        conn_comps.back().push_back(u);
        vis[u] = true;
        for (auto& [v, w] : adj[u]) {
            if (vis[v]) {
                pair<long long, long long> res = coeffs[u] + coeffs[v];
                if (res.first == 0 && res.second != w) {
                    bad = true;
                } else if (res.first != 0 && val == emp) {
                    if (res.first == 2) {
                        val = w - res.second;
                    } else {
                        val = res.second - w;
                    }
                } else if (res.first != 0 && val != emp) {
                    if (res.first == 2) {
                        if (val != w - res.second) {
                            bad = true;
                            return;
                        }
                    } else if (res.first == -2) {
                        if (val != res.second - w) {
                            bad = true;
                            return;
                        }
                    }
                }
            } else {
                coeffs[v] = make_pair(-coeffs[u].first, w - coeffs[u].second);
                dfs(v);
            }
        }
    };
    vector<long long> vals;
    for (long long i = 0; i < n; i++) {
        if (!vis[i]) {
            conn_comps.emplace_back();
            val = emp;
            coeffs[i] = {1, 0};
            dfs(i);
            vals.push_back(val);
        }
    }
    for (long long i = 0; i < n; i++) {
        vis[i] = false;
    }
    vector<double> ans(n);
    function<void(long long)> out = [&](long long u) {
        vis[u] = true;
        for (auto& [v, w] : adj[u]) {
            if (!vis[v]) {
                ans[v] = (double)w - ans[u];
                out(v);
            }
        }
    };
    if (bad) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
        for (long long i = 0; i < conn_comps.size(); i++) {
            if (vals[i] == emp) {
                vector<long long> compvals;
                for (long long j : conn_comps[i]) {
                    if (coeffs[j].first == 1) {
                        compvals.push_back(-coeffs[j].second);
                    } else {
                        compvals.push_back(coeffs[j].second);
                    }
                }
                sort(compvals.begin(), compvals.end());
                ans[conn_comps[i][0]] = (double)(compvals[(compvals.size() - 1) / 2] + compvals[compvals.size() / 2]) / (double)2;
                out(conn_comps[i][0]);
            } else {
                ans[conn_comps[i][0]] = (double)vals[i] / (double)2;
                out(conn_comps[i][0]);
            }
        }
        for (long long i = 0; i < n; i++) {
            cout << fixed << setprecision(6) << ans[i] << ' ';
        }
    }
}