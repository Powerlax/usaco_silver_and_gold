//
// Created by innav_z3e3dq9 on 11/2/2024.
//

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

int cycle_len(int start, const int n) {
    int ans = INT_MAX;
    vector<int> dist(n, -1);
    queue<int> bfs;
    dist[start] = 0;
    bfs.push(start);
    while (!bfs.empty()) {
        int node = bfs.front();
        bfs.pop();
        for (int adj_node : adj[node]) {
            if (dist[adj_node] == -1) {
                dist[adj_node] = dist[node] + 1;
                bfs.push(adj_node);
            } else if (dist[adj_node] >= dist[node]) {
                ans = min(ans, 1 + dist[adj_node] + dist[node]);
            }
        }
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    adj = vector<vector<int>>(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int res = INT_MAX;
    for (int i = 0; i < n; i++) {
        res = min(res, cycle_len(i, n));
    }
    if (res == INT_MAX) {
        cout << -1 << endl;
        return 0;
    }
    cout << res << endl;
}