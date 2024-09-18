//
// Created by innav_z3e3dq9 on 8/6/2024.
//

#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<bool> color;
vector<vector<int>> adj;

void dfs(int node, bool color_to_use) {
    visited[node] = true;
    color[node] = color_to_use;
    color_to_use = !color_to_use;
    for (auto i : adj[node]) {
        if (!visited[i]) {
            dfs(i, color_to_use);
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
    color = vector<bool>(n);
    visited = vector<bool>(n);
    dfs(0, true);
    int red = 0, blue = 0;
    for (int i = 0; i<n; i++) {
        if (color[i]) {
            red++;
        } else {
            blue++;
        }
    }
    cout << (red*blue)-(n-1) << endl;
    return 0;
}