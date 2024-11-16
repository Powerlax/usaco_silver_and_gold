//
// Created by innav_z3e3dq9 on 11/12/2024.
//

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> emp;

vector<int> dfs(const int node, vector<int> &curr) {
    visited[node] = true;
    for (const auto i : adj[node]) {
        curr.push_back(i);
        if (visited[i]) {
            return curr;
        }
        auto res = dfs(i, curr);
        if (!res.empty()) {
            return res;
        }
        curr.pop_back();
    }
    return emp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    vector<pair<int, int>> deg(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        deg[a].second++;
        deg[b].first++;
    }
    visited.resize(n);
    for (int i = 0; i < n; i++) {
        if (deg[i].first && deg[i].second) {
            fill(visited.begin(), visited.end(), false);
            auto res = dfs(i, emp);
            if (!res.empty()) {
                res = dfs(res[res.size()-1], emp);
                cout << res.size() << endl;
                for (auto j : res) {
                    cout << j+1 << " ";
                }
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}