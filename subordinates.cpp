//
// Created by innav_z3e3dq9 on 8/9/2024.
//

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> node_sizes;

void dfs(int node) {
    node_sizes[node] = 1;
    for (int i = 0; i<adj[node].size(); i++) {
        dfs(adj[node][i]);
        node_sizes[node] += node_sizes[adj[node][i]];
    }
}

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    int n;
    cin >> n;
    adj = vector<vector<int>>(n);
    for (int i = 1; i<n; i++) {
        int temp;
        cin >> temp;
        temp--;
        adj[temp].push_back(i);
    }
    node_sizes = vector<int>(n);
    dfs(0);
    for (int i = 0; i<n; i++) {
        cout << node_sizes[i]-1 << " ";
    }
    return 0;
}