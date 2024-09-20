//
// Created by innav_z3e3dq9 on 8/9/2024.
//

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> depth;

void dfs(int node, int last) {
    for (auto i : adj[node]) {
        if (i != last) {
            depth[i] = depth[node] + 1;
            dfs(i, node);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    adj = vector<vector<int>>(n);
    for (int i = 0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    depth = vector<int>(n);
    dfs(0,0);
    int node, strongest = -1;
    for (int i = 0; i<n; i++) {
        if (depth[i] > strongest) {
            node = i;
            strongest = depth[i];
        }
    }
    depth = vector<int>(n);
    dfs(node, node);
    node = -1, strongest = -1;
    for (int i = 0; i<n; i++) {
        if (depth[i] > strongest) {
            node = i;
            strongest = depth[i];
        }
    }
    cout << strongest;
    return 0;
}