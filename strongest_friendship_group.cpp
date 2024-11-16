//
// Created by innav_z3e3dq9 on 11/3/2024.
//

#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> elements;

public:
    explicit DisjointSet(const int n) : elements(n, -1) {};

    int find(const int x) {
        if (elements[x] < 0) {
            return x;
        }
        return elements[x] = find(elements[x]);
    }

    bool unite(const int x, const int y) {
        int x_root = find(x);
        int y_root = find(y);
        if (x_root == y_root) {
            return false;
        }
        if (elements[x_root] > elements[y_root]) {
            swap(x_root, y_root);
        }
        elements[x_root] += elements[y_root];
        elements[y_root] = x_root;
        return true;
    }

    bool connected(const int x, const int y) {
        return find(x) == find(y);
    }

    int size(const int x) {
        return -elements[find(x)];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> connections(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        ++connections[u];
        ++connections[v];
    }
    set<array<int, 2>> vertices;
    for (int i = 0; i < n; ++i) {
        vertices.insert({connections[i], i});
    }
    vector<int> order;
    vector<int> degrees;
    vector active(n, true);
    for (int i = 0; i < n; ++i) {
        const auto top = *vertices.begin();
        const int u = top[1];
        const int degree = top[0];
        order.push_back(u);
        degrees.push_back(degree);
        active[u] = false;
        for (const int v : adj[u]) {
            if (active[v]) {
                vertices.erase({connections[v], v});
                --connections[v];
                vertices.insert({connections[v], v});
            }
        }
        vertices.erase({connections[u], u});
    }
    reverse(order.begin(), order.end());
    reverse(degrees.begin(), degrees.end());
    active.assign(n, false);
    DisjointSet dsu(n);
    int mx = 1;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        const int u = order[i];
        active[u] = true;
        for (const int v : adj[u]) {
            if (active[v]) {
                dsu.unite(u, v);
                mx = max(mx, dsu.size(u));
            }
        }
        ans = max(ans, static_cast<long long>(1) * mx * degrees[i]);
    }
    cout << ans << endl;
    return 0;
}