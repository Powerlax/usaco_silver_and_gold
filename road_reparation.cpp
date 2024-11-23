//
// Created by innav_z3e3dq9 on 11/22/2024.
//

#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parents;
    vector<int> sizes;

public:
    explicit DisjointSet(const int n) : parents(n, -1), sizes(n, 1) {}

    int find(const int x) {
        if (parents[x] == -1) {
            return x;
        }
        return parents[x] = find(parents[x]);
    }

    bool unite(const int x, const int y) {
        int x_root = find(x);
        int y_root = find(y);
        if (x_root == y_root) {
            return false;
        }
        if (sizes[x_root] < sizes[y_root]) {
            swap(x_root, y_root);
        }
        sizes[x_root] += sizes[y_root];
        parents[y_root] = x_root;
        return true;
    }

    bool connected(const int x, const int y) {
        return find(x) == find(y);
    }
};

struct Edge {
    int a, b, cost;
};

bool comp(const Edge &a, const Edge &b) {
    return a.cost < b.cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        edges[i] = {a, b, c};
    }
    sort(edges.begin(), edges.end(), comp);
    DisjointSet dsu(n);
    long long ans = 0;
    for (const auto [a, b, cost] : edges) {
        if (dsu.unite(a, b)) {
            ans += cost;
        }
    }
    const int root = dsu.find(0);
    for (int i = 1; i < n; i++) {
        if (dsu.find(i) != root) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    cout << ans << endl;
}