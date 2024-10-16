//
// Created by innav_z3e3dq9 on 8/4/2024.
//

#include <bits/stdc++.h>
using namespace std;

pair<vector<vector<int>>, vector<vector<int>>> adj;
vector<bool> visited;

void dfs(int node, bool direction) {
    visited[node] = true;
    if (direction) {
        for (auto i : adj.first[node]) {
            if (!visited[i]) {
                dfs(i, direction);
            }
        }
    } else {
        for (auto i : adj.second[node]) {
            if (!visited[i]) {
                dfs(i, direction);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    adj.first = vector<vector<int>>(n);
    adj.second = vector<vector<int>>(n);
    visited = vector<bool>(n);
    for (int i = 0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj.first[a].push_back(b);
        adj.second[b].push_back(a);
    }
    for (int i = 0; i<n; i++) {
        visited[i] = false;
    }
    dfs(0, true);
    for (int i = 0; i<n; i++) {
        if (!visited[i]) {
            cout << "NO" << endl;
            cout << 1 << " " << i+1;
            return 0;
        }
        visited[i] = false;
    }
    dfs(0, false);
    for (int i = 0; i<n; i++) {
        if (!visited[i]) {
            cout << "NO" << endl;
            cout << i+1 << " " << 1;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}