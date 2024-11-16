//
// Created by innav_z3e3dq9 on 8/5/2024.
//

#include <bits/stdc++.h>
using namespace std;

const int N = 501;
vector<int> graph[N], revgraph[N];
vector<bool> vis(N), vis2(N);
vector<int> path;
vector<bool> comp(N);

void dfs(int node) {
    vis[node] = true;
    for (int i : graph[node]) {
        if (!vis[i]) { dfs(i); }
    }
    path.push_back(node);
}

void dfs2(int node, vector<int> &comp_nodes) {
    vis2[node] = true;
    for (int i : revgraph[node]) {
        if (!vis2[i]) { dfs2(i, comp_nodes); }
    }
    comp[node] = true;
    comp_nodes.push_back(node);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        graph[i].resize(n);
        for (int j = 0; j < n; j++) { cin >> graph[i][j]; }
        while (graph[i].back() != i) { graph[i].pop_back(); }
        for (int j : graph[i]) { revgraph[j].push_back(i); }
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) { dfs(i); }
    }
    reverse(path.begin(), path.end());
    vector<int> ans(n + 1);
    for (int i : path) {
        if (!vis2[i]) {
            vector<int> comp_nodes;
            dfs2(i, comp_nodes);
            for (int j : comp_nodes) {
                for (int k : graph[j]) {
                    if (comp[k]) {
                        ans[j] = k;
                        break;
                    }
                }
            }
            for (int j : comp_nodes) { comp[j] = false; }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
}