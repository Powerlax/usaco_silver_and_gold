//
// Created by innav_z3e3dq9 on 11/5/2024.
//

#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parents;
    vector<int> sizes;
    public:
        explicit DSU(const int size) : parents(size, -1), sizes(size, 1) {}

        int find(const int x) {
            if (parents[x] == x || parents[x] == -1) {
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

        bool is_connected(const int x, const int y) {
            return find(x) == find(y);
        }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    auto graph = DSU(n);
    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t) {
            cout << static_cast<int>(graph.is_connected(a, b)) << endl;
        } else {
            graph.unite(a, b);
        }
    }
    return 0;
}