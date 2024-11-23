//
// Created by innav_z3e3dq9 on 11/22/2024.
//

#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<long long, long long>>> adj;
vector<long long> du, dv, ds;
vector<vector<long long>> dp(2);
long long ans;
vector<bool> visited;

void dijkstra1(long long start, vector<long long> &arr) {
    fill(visited.begin(), visited.end(), false);
    priority_queue<pair<long long, long long>> pq;
    pq.emplace(0, start);
    while (!pq.empty()) {
        long long c, node;
        tie(c, node) = pq.top();
        pq.pop();
        if (!visited[node]) {
            arr[node] = -c;
            visited[node] = true;
            for (auto &[fst, snd] : adj[node]) {
                pq.emplace(c - snd, fst);
            }
        }
    }
}

void dijkstra2(long long start, const long long end) {
    fill(dp[0].begin(), dp[0].end(), LLONG_MAX/2);
    fill(dp[1].begin(), dp[1].end(), LLONG_MAX/2);
    fill(visited.begin(), visited.end(), false);
    priority_queue<pair<long long, pair<long long, long long>>> pq;
    pq.push({0, {start, 0}});
    dp[0][0] = dp[1][0] = LLONG_MAX / 2;
    while (!pq.empty()) {
        long long c, node, par;
        pair<long long, long long> p;
        tie(c, p) = pq.top();
        tie(node, par) = p;
        pq.pop();
        if (!visited[node]) {
            visited[node] = true;
            ds[node] = -c;
            dp[0][node] = min(du[node], dp[0][par]);
            dp[1][node] = min(dv[node], dp[1][par]);
            for (auto [fst, snd] : adj[node]) {
                pq.push({c - snd, {fst, node}});
            }
        } else if (-c == ds[node]) {
            if (min(du[node], dp[0][par]) + min(dv[node], dp[1][par]) <= dp[0][node] + dp[1][node]) {
                dp[0][node] = min(du[node], dp[0][par]);
                dp[1][node] = min(dv[node], dp[1][par]);
            }
        }
    }
    ans = min(ans, dp[0][end] + dp[1][end]);
}

int main() {
    iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long n, m, s, t, u, v;
    cin >> n >> m >> s >> t >> u >> v;
    adj.resize(n+1);
    for (int i = 0; i < m; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    du.resize(n+1);
    dv.resize(n+1);
    ds.resize(n+1);
    dp[0].resize(n+1);
    dp[1].resize(n+1);
    visited.resize(n+1);
    dijkstra1(u, du);
    dijkstra1(v, dv);
    ans = du[v];
    dijkstra2(s, t);
    dijkstra2(t, s);
    cout << ans << endl;
    return 0;
}