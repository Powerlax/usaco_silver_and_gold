//
// Created by innav_z3e3dq9 on 12/29/2024.
//

#include <bits/stdc++.h>
using namespace std;

struct Cow {
    int id, from, to;
    bool is_first_pref;
};

vector<vector<Cow>> adj;
queue<int> permutation;
vector<bool> visited_cycle;
vector<bool> is_fed;
vector<bool> visited;
int root_node = -1;
int ignored_edge = -1;

void find_components(const int node, const int parent = -1) {
    visited_cycle[node] = true;
    for (const Cow &next : adj[node]) {
        if (visited_cycle[next.to]) {
            if (root_node == -1 && next.to != parent) {
                if (next.is_first_pref) {
                    root_node = next.to;
                } else {
                    root_node = node;
                }
                ignored_edge = next.id;
                permutation.push(next.id);
                is_fed[next.id] = true;
            }
        } else {
            find_components(next.to, node);
        }
    }
}

void dfs(const int node) {
    visited[node] = true;
    for (const Cow &next : adj[node]) {
        if (!visited_cycle[next.to] && next.id != ignored_edge) {
            is_fed[next.id] = true;
            permutation.push(next.id);
            dfs(next.to);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    adj.resize(m);
    visited_cycle.resize(m);
    visited.resize(m);
    is_fed.resize(m);
    for (int i = 1; i < n + 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(Cow{i, b, a, false});
        adj[b].push_back(Cow{i, a, b, true});
    }
    for (int i = 0; i < m; i++) {
        if (!visited_cycle[i]) {
            find_components(i);
            if (root_node > 0) {
                dfs(root_node);
            } else {
                dfs(i);
            }
        }
    }
    int unfed_cows = 0;
    for (int i = 1; i < n; i++) {
        if (!is_fed[i]) {
            unfed_cows++;
            permutation.push(i);
        }
    }
    cout << unfed_cows << endl;
    while (!permutation.empty()) {
        cout << permutation.front() << endl;
        permutation.pop();
    }
    return 0;
}