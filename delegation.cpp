//
// Created by innav_z3e3dq9 on 2/9/2025.
//
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> g[N];
int to_be_merged[N];

bool dfs(int node, int p, int k) {
    map<int, int> to_be_merged_count;
    for (int i : g[node]) {
        if (i == p) {
            continue;
        }
        if (!dfs(i, node, k)) {
            return false;
        }
        const int curr_merge = to_be_merged[i] + 1;
        if (curr_merge != k) {
            to_be_merged_count[curr_merge]++;
        }
    }
    for (auto [key, value] : to_be_merged_count) {
        if (key == k - key) {
            if (value % 2 == 1) {
                if (to_be_merged[node]) {
                    return false;
                }
                to_be_merged[node] = key;
            }
        } else {
            if (value > to_be_merged_count[k - key]) {
                if (value - to_be_merged_count[k - key] > 1 || to_be_merged[node]) {
                    return false;
                }
                to_be_merged[node] = key;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("deleg.in", "r", stdin);
    freopen("deleg.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[--u].push_back(--v);
        g[v].push_back(u);
    }
    for (int k = 1; k <= n - 1; k++) {
        if ((n - 1) % k != 0) {
            cout << 0;
        } else {
            fill_n(to_be_merged, n, 0);
            cout << dfs(0, 0, k);
        }
    }
    return 0;
}
