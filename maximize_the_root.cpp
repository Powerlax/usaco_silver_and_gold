//
// Created by innav_z3e3dq9 on 1/15/2025.
//

#include <bits/stdc++.h>
using namespace std;

vector<int> a;
vector<vector<int>> children;

int dfs(const int node) {
    if (children[node].size() == 0) {
        return a[node];
    }
    int lowest = INT_MAX;
    for (const int child : children[node]) {
        lowest = min(lowest, dfs(child));
    }
    return a[node] + lowest;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        a.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        children.resize(n, vector<int>());
        for (int i = 1; i < n; i++) {
            int parent;
            cin >> parent;
            parent--;
            children[parent].push_back(i);
        }
        cout << dfs(0) << endl;
    }
    return 0;
}