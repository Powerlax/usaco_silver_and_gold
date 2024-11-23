//
// Created by innav_z3e3dq9 on 11/21/2024.
//

#include <bits/stdc++.h>
using namespace std;

struct Pipe {
    int to, cost, flow_rate;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("pump.in", "r", stdin);
    freopen("pump.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<vector<Pipe>> adj(n);
    set<int> flows;
    for (int i = 0; i < m; i++) {
        int a, b, c, f;
        cin >> a >> b >> c >> f;
        a--;
        b--;
        adj[a].push_back({b, c, f});
        adj[b].push_back({a, c, f});
        flows.insert(f);
    }
    int ans = -1;
    for (const int min_flow : flows) {
        priority_queue<pair<int, int>> next;
        vector cost(n, INT_MAX);
        vector<bool> visited(n);
        cost[0] = 0;
        next.emplace(0, 0);
        while (!next.empty()) {
            const auto [fst, snd] = next.top();
            next.pop();
            if (snd != cost[fst] || visited[fst]) {
                continue;
            }
            for (auto [i, cost_pipe, flow_rate] : adj[fst]) {
                int total_cost = snd + cost_pipe;
                if (flow_rate < min_flow || visited[i]) {
                    continue;
                }
                if (cost[i] > total_cost) {
                    cost[i] = total_cost;
                    next.emplace(i, total_cost);
                }
            }
        }
        if (cost[n - 1] == INT_MAX) {
            continue;
        }
        const double ratio = static_cast<double>(min_flow) / static_cast<double>(cost[n - 1]);
        ans = max(ans, static_cast<int>(ratio * 1e6));
    }
    cout << ans << endl;
    return 0;
}