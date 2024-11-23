//
// Created by innav_z3e3dq9 on 11/19/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        adj[a].emplace_back(b, c);
    }
    vector dist(n, LLONG_MAX);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> frontier;
    int start = 0;
    dist[start] = 0;
    frontier.emplace(0, start);
    while (!frontier.empty()) {
        const auto [distance, node] = frontier.top();
        frontier.pop();
        if (distance != dist[node]) {
            continue;
        }
        for (const auto &[fst, snd] : adj[node]) {
            if (distance + snd < dist[fst]) {
                frontier.emplace(dist[fst] = distance + snd, fst);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << dist[i] << ' ';
    }
    return 0;
}