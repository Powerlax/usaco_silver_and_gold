//
// Created by innav_z3e3dq9 on 10/26/2024.
//

#include <bits/stdc++.h>
using namespace std;

vector<int> a, v;
vector<vector<int>> reversed_graph;
vector<bool> visited;

void dfs(int y) {
    if (visited[y]) {
        return;
    }
    visited[y] = true;
    for (int c : reversed_graph[y]) {
        dfs(c);
    }
}

int min_in_cycle(int curr) {
    int y = a[curr];
    int z = a[y];
    while (y != z) {
        y = a[y];
        z = a[a[z]];
    }
    int min_v = v[y];
    y = a[y];
    while (y != z) {
        min_v = min(min_v, v[y]);
        y = a[y];
    }
    dfs(y);
    return min_v;
}

int main() {
    int n;
    cin >> n;
    v.resize(n);
    a.resize(n);
    visited.resize(n);
    reversed_graph.resize(n);
    long long max_moos = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> v[i];
        a[i]--;
        reversed_graph[a[i]].push_back(i);
        max_moos += v[i];
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            max_moos -= min_in_cycle(i);
        }
    }
    cout << max_moos << endl;
}