//
// Created by innav_z3e3dq9 on 8/17/2024.
//

#include <bits/stdc++.h>
using namespace std;

vector<int> bales;
vector<vector<int>> adj;
vector<vector<int>> paths;
vector<int> overflow;

void dfs(int node, int parent) {
    for (int i : adj[node]) {
        if (i == parent) continue;
        dfs(i, node);
        if (overflow[i] > 0) {
            vector<int> temp;
            temp.push_back(i+1);
            temp.push_back(node+1);
            temp.push_back(overflow[i]);
            paths.push_back(temp);
            overflow[node] += overflow[i];
        } else if (overflow[i] < 0) {
            vector<int> temp;
            temp.push_back(i+1);
            temp.push_back(node+1);
            temp.push_back(-overflow[i]);
            paths.push_back(temp);
            overflow[node] += overflow[i];
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
    int target = 0;
    for (int i = 0; i<n; i++) {
        int temp;
        cin >> temp;
        bales.push_back(temp);
        target += temp;
    }
    target /= n;
    overflow = vector<int>(n);
    for (int i = 0; i<n; i++) {
        overflow[i] = bales[i] - target;
    }
    for (int i = 0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, 0);
    cout << paths.size() << endl;
    for (auto i: paths) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}