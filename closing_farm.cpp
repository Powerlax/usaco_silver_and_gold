//
// Created by innav_z3e3dq9 on 8/4/2024.
//

#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int n, m;
const int MAX_N = 3000;
vector<vector<int>> adj(MAX_N);
vector<int> vis(MAX_N);
vector<int> closed(MAX_N);
int nodes = 0;

void dfs(int node) {
    if (vis[node] || closed[node]) return;
    nodes++;
    vis[node] = true;
    for (int u : adj[node]) {
        if (!vis[u]) dfs(u);
    }
}

int main() {
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> ord(n);
    for (int i = 0; i < n; i++) cin >> ord[i];
    dfs(1);
    if (nodes == n) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    for (int i = 0; i < n - 1; i++) {
        nodes = 0;
        closed[ord[i]] = true;
        fill(vis.begin(), vis.end(), false);
        dfs(ord[n - 1]);
        if (nodes == n - i - 1) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
}