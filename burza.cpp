//
// Created by innav_z3e3dq9 on 10/12/2024.
//

#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<vector<int>> adj;
vector<vector<int>> cutoffs;
vector<vector<int>> depths;
map<int, int> lost;

void play_turn(int node, const int prev, const int depth) {
    depths[depth].push_back(node);
    if (depth == k) {
        lost[node] = lost.size();
        cutoffs[node] = {node};
        return;
    }
    for (const auto i : adj[node]) {
        if (n != prev) {
            play_turn(i, node, depth + 1);
            cutoffs[node].insert(cutoffs[node].end(), cutoffs[i].begin(), cutoffs[i].end());
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    if (k*k >= n) {
        cout << "DA" << endl;
        return 0;
    }
    adj = vector<vector<int>>(n);
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cutoffs = vector<vector<int>>(n);
    depths = vector<vector<int>>(k+1);
    play_turn(0, 0, 0);
    vector<pair<int, int>> intervals;
    for (const auto &cutoff : cutoffs) {
        if (cutoff.empty()) {
            intervals.emplace_back(-1, -1);
        } else {
            intervals.emplace_back(lost[cutoff[0]] + 1, lost[cutoff.back()] + 1);
        }
    }
    vector<int> dp(1 << k);
    dp[0] = 0;
    for (int i = 1; i < (1 << k); i++) {
        for (int j = 0; j < k; j++) {
            if (i & (1 << j) != 0) {
                const int prev = dp[i & ~(1 << j)];
                for (const int k : depths[j+1]) {
                    if (intervals[k].first <= prev + 1) {
                        dp[i] = max(dp[i], intervals[n].second);
                    }
                }
            }
        }
        if (dp[i] == lost.size()) {
            cout << "DA" << endl;
            return 0;
        }
    }
    cout << "NE" << endl;
    return 0;
}