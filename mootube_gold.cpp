//
// Created by innav_z3e3dq9 on 11/10/2024.
//

#include <bits/stdc++.h>
using namespace std;

class DisjointSets {
    vector<int> parents;
    vector<int> sizes;

    public:
        explicit DisjointSets(const int size) : parents(size, -1), sizes(size, 1) {}

        int find_root(const int x) {
            if (parents[x] == -1 || parents[x] == x) {
                return x;
            }
            return parents[x] = find_root(parents[x]);
        }

        bool unite_subsets(const int x, const int y) {
            int x_root = find_root(x);
            int y_root = find_root(y);
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
            return find_root(x) == find_root(y);
        }

        int get_size(const int x) {
            return sizes[find_root(x)];
        }
};

struct Edge {
    int vid_1, vid_2, relevance;
};

bool comp_edge(const Edge &a, const Edge &b) {
    return a.relevance < b.relevance;
}

struct Query {
    int id, video, k;
};

bool comp_query(const Query &a, const Query &b) {
    return a.k < b.k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen("mootube.in", "r", stdin);
    //freopen("mootube.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    vector<Edge> edges(n-1);
    for (int i = 0; i < n-1; i++) {
        cin >> edges[i].vid_1 >> edges[i].vid_2 >> edges[i].relevance;
        edges[i].vid_1--;
        edges[i].vid_2--;
    }
    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        queries[i].id = i;
        cin >> queries[i].k >> queries[i].video;
        queries[i].video--;
    }
    sort(edges.begin(), edges.end(), comp_edge);
    sort(queries.begin(), queries.end(), comp_query);
    DisjointSets dsu(n);
    vector<int> ans(q);
    int index = 0;
    for (auto query : queries) {
        while (index < static_cast<int>(edges.size()) && edges[index].relevance >= query.k) {
            dsu.unite_subsets(edges[index].vid_1, edges[index].vid_2);
            index++;
        }
        ans[query.id] = dsu.get_size(query.video) - 1;
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}