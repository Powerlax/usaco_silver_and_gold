//
// Created by innav_z3e3dq9 on 10/13/2024.
//

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<vector<int>>> adj(n);
    vector<int> deg(n+1);
    for (int i = 0; i < m; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        adj[b].push_back({a, l});
        deg[a]++;
    }
    vector<int> start_nodes;
    for (int i = 1; i <= n; i++) {
        if (!deg[i]) {
            start_nodes.push_back(i);
        }
    }
    vector<vector<vector<long long>>> paths(n+1);
    vector<int> rank(n+1), len(n+1);
    vector<long long> sum(n+1);
    while (static_cast<int>(start_nodes.size())) {
        vector<int> end_nodes;
        for (const auto i : start_nodes) {
            for (auto j : adj[i]) {
                int v = j[0], l = j[1];
                paths[v].push_back({-len[i], l, rank[i], sum[i]+l});
                deg[v]--;
                if (deg[v] == 0) {
                    len[v] = len[i] + 1;
                    end_nodes.push_back(v);
                }
            }
        }
        swap(start_nodes, end_nodes);
        vector<vector<long long>> store;
        for (auto x : start_nodes) {
            sort(paths[x].begin(), paths[x].end());
            vector<long long> use = paths[x][0];
            sum[x] = use[3];
            store.push_back({use[1], use[2], x});
        }
        sort(store.begin(), store.end());
        for(int i = 0; i < store.size(); i++){
            rank[store[i][2]] = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << len[i] << " " << sum[i] << endl;
    }
}