//
// Created by innav_z3e3dq9 on 12/8/2024.
//

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj, parents;
vector<int> start_time, end_time, binary_indexed_tree;
int timer = 1;

void euler_tour(const int node, const int parent) {
    start_time[node] = timer++;
    parents[node][0] = parent;
    for (int i = 1; i < 22; i++) {
        parents[node][i] = parents[parents[node][i - 1]][i - 1];
    }
    for (const auto child : adj[node]) {
        if (child != parent) {
            euler_tour(child, node);
        }
    }
    end_time[node] = timer;
}

void update_tree(int node, const int value) {
    while (node <= timer) {
        binary_indexed_tree[node] ^= value;
        node += (node & -node);
    }
}

int query(int node) {
    int ans = 0;
    while (node > 0) {
        ans ^= binary_indexed_tree[node];
        node -= (node & -node);
    }
    return ans;
}

bool check(const int a, const int b) {
    return start_time[a] <= start_time[b] && end_time[a] >= end_time[b];
}

int lca(int a, const int b) {
    if (check(a, b)) {
        return a;
    }
    for (int i = 21; i >= 0; i--) {
        if (parents[a][i] >= 0 && !check(parents[a][i], b)) {
            a = parents[a][i];
        }
    }
    return parents[a][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen("cowland.in", "r", stdin);
    //freopen("cowland.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    vector<int> enjoyment(n);
    for (int i = 0; i < n; i++) {
        cin >> enjoyment[i];
    }
    adj.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    start_time.resize(n);
    end_time.resize(n);
    binary_indexed_tree.resize(n * 4);
    parents.resize(n, vector<int>(22));
    euler_tour(0, 0);
    for (int i = 0; i < n; i++) {
        update_tree(start_time[i], enjoyment[i]);
        update_tree(end_time[i], enjoyment[i]);
    }
    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        a--;
        if (t == 1) {
            update_tree(start_time[a], enjoyment[a]);
            update_tree(end_time[a], enjoyment[a]);
            enjoyment[a] = b;
            update_tree(start_time[a], enjoyment[a]);
            update_tree(end_time[a], enjoyment[a]);
        } else {
            b--;
            cout << ((query(start_time[a]) ^ query(end_time[b])) ^ enjoyment[lca(a, b)]) << endl;
        }
    }
    return 0;
}