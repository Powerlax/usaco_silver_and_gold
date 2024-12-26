//
// Created by innav_z3e3dq9 on 12/5/2024.
//

#include <bits/stdc++.h>
using namespace std;

class BinaryIndexedTree {
    int n;
    vector<long long> tree;
    vector<long long> values;

public:
    explicit BinaryIndexedTree(const int len) : n(len), tree(len + 1), values(len) {}

    void set(int node, long long value) {
        value = value - values[node];
        values[node] += value;
        for (node++; node <= n; node += node & -node) {
            tree[node] += value;
        }
    }

    [[nodiscard]] long long query(int node) const {
        long long ans = 0;
        for (node++; node > 0; node -= node & -node) {
            ans += tree[node];
        }
        return ans;
    }
};

vector<vector<int>> adj;
vector<int> tree_start;
vector<int> tree_end;
int step_num = 0;

void euler_tour(const int node, const int parent) {
    tree_start[node] = step_num++;
    for (const auto child : adj[node]) {
        if (child != parent) {
            euler_tour(child, node);
        }
    }
    tree_end[node] = step_num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> node_values(n);
    for (int i = 0; i < n; i++) {
        cin >> node_values[i];
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
    tree_start.resize(n);
    tree_end.resize(n);
    euler_tour(0, -1);
    BinaryIndexedTree tree(n);
    for (int i = 0; i < n; i++) {
        tree.set(tree_start[i], node_values[i]);
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int s, x;
            cin >> s >> x;
            s--;
            tree.set(tree_start[s], x);
        } else {
            int s;
            cin >> s;
            s--;
            cout << tree.query(tree_end[s] - 1) -
            (tree_start[s] == 0 ? 0 : tree.query(tree_start[s] - 1)) << endl;
        }
    }
    return 0;
}