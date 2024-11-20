//
// Created by innav_z3e3dq9 on 11/16/2024.
//

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void topo_sorting(vector<vector<pair<int, int>>> &graph, vector<bool> &visited, vector<int> &toposort, const int node) {
    visited[node] = true;
    for (const auto i : graph[node]) {
        int a, b;
        tie(a, b) = i;
        if (visited[a]) {
            continue;
        }
        topo_sorting(graph, visited, toposort, a);
    }
    toposort.push_back(node);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("timeline.in", "r", stdin);
    freopen("timeline.out", "w", stdout);
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> start(n + 1);
    for (int i = 1; i <= n; i++) { cin >> start[i]; }
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < c; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
    }
    vector<bool> visited(n + 1);
    vector<int> toposort;
    for (int i = 1; i <= n; i++) {
        if (visited[i]) { continue; }
        topo_sorting(graph, visited, toposort, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        for (auto j : graph[toposort[i]]) {
            int a, b;
            tie(a, b) = j;
            start[a] = max(start[a], start[toposort[i]] + b);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << start[i] << "\n";
    }
}