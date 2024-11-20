//
// Created by innav_z3e3dq9 on 11/16/2024.
//

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<set<int>> depths;

void dfs(const int node, const int depth) {
    depths[node].insert(depth);
    for (const auto i : adj[node]) {
        dfs(i, depth + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n1, n2, m1, m2;
    cin >> n1 >> n2 >> m1 >> m2;
    vector<vector<int>> adj1(n1), adj2(n2);
    for (int i = 0; i < m1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj1[a].push_back(b);
    }
    for (int i = 0; i < m2; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj2[a].push_back(b);
    }
    adj = adj1;
    depths.resize(n1);
    dfs(0, 0);
    const set<int> depth1 = depths[n1 - 1];
    adj = adj2;
    depths.resize(n2);
    dfs(0, 0);
    const set<int> depth2 = depths[n2 - 1];
    set<int> combined;
    for (const int i : depth1) {
        for (const int j : depth2) {
            combined.insert(i+j);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int a;
        cin >> a;
        cout << (combined.find(a) != combined.end() ? "Yes" : "No") << endl;
    }
    return 0;
}