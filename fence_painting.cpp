//
// Created by innav_z3e3dq9 on 8/4/2024.
//

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> curr;

void dfs(int node) {
    visited[node] = true;
    curr.push_back(node);
    for (int i : adj[node]) {
        if (!visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    freopen("fenceplan.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> coords;
    for (int i = 0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        coords.emplace_back(x, y);
    }
    adj = vector<vector<int>>(n);
    for (int i = 0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    visited = vector<bool>(n);
    for (int i = 0; i<n; i++) {visited[i]=false;}
    vector<vector<int>> all;
    for (int i = 0; i<n; i++) {
        if (!visited[i]) {
            curr.clear();
            dfs(i);
            all.push_back(curr);
        }
    }

    int ans = INT_MAX;
    for (auto & i : all) {
        int x_max = 0, x_min = INT_MAX, y_max = 0, y_min = INT_MAX;
        for (int j : i) {
            x_max = max(x_max, coords[j].first);
            x_min = min(x_min, coords[j].first);
            y_max = max(y_max, coords[j].second);
            y_min = min(y_min, coords[j].second);
        }
        ans = min(ans, (((x_max-x_min)*2) + ((y_max-y_min)*2)));
    }
    freopen("fenceplan.out", "w", stdout);
    cout << ans;
    return 0;
}