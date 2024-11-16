//
// Created by innav_z3e3dq9 on 11/10/2024.
//

#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parents;
    vector<int> sizes;

public:
    explicit DisjointSet(const int n): parents(n, -1), sizes(n, 1) {}

    int find(const int child) {
        if (parents[child] == -1 || parents[child] == child) {
            return child;
        }
        return parents[child] = find(parents[child]);
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

struct Edge {
    int a, b, distance;
};

bool comp(const Edge &a, const Edge &b) {
    return a.distance < b.distance;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    int n;
    cin >> n;
    vector<pair<int, int>> pos(n);
    for (int i = 0; i < n; i++) {
        cin >> pos[i].first >> pos[i].second;
    }
    vector<Edge> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            const int dx = pos[i].first - pos[j].first;
            const int dy = pos[i].second - pos[j].second;
            edges.push_back({i, j, dx * dx + dy * dy});
        }
    }
    sort(edges.begin(), edges.end(), comp);
    int ans = 0;
    int comp_num = n;
    DisjointSet dsu(n);
    for (const auto &[a, b, distance] : edges) {
        if (dsu.unite(a, b)) {
            ans = distance;
            if (--comp_num == 1) {
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}