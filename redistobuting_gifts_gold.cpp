//
// Created by innav_z3e3dq9 on 10/12/2024.
//

#include <bits/stdc++.h>
using namespace std;

vector<long long> ans;
vector<int> adj;

long long solve_adj(const vector<int> &new_adj) {
    const int n = static_cast<int>(size(new_adj));
    vector<long long> dp(1 << n);
    dp[0] = 1;
    for (int i = 0; i < (1 << n); i++) {
        const int p = __builtin_popcount(i);
        for (int j = 0; j < n; j++) {
            if (!(i & (1 << j))) {
                if (new_adj.at(p) & (1 << j)) {
                    dp[i ^ (1 << j)] += dp[i];
                }
            }
        }
    }
    return dp.back();
}

long long solve_subset(const int mask, const int n) {
    if (!ans[mask]) {
        vector<int> bits;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                bits.push_back(i);
            }
        }
        vector<int> new_adj(size(bits));
        for (size_t i = 0; i < size(bits); i++) {
            for (size_t j = 0; j < size(bits); j++) {
                if (adj[bits[i]] & (1 << bits[j])) {
                    new_adj[i] ^= 1 << j;
                }
            }
        }
        ans[mask] = solve_adj(new_adj);
    }
    return ans[mask];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    ans = vector<long long>(1 << n);
    adj = vector<int>(n);
    for (int i = 0; i < n; i++) {
        vector<int> preferences(n);
        for (int j = 0; j < n; j++) {
            cin >> preferences[j];
            preferences[j]--;
        }
        for (int j = 0; j < n; j++) {
            adj[i] |= 1 << preferences[j];
            if (preferences[j] == i) {
                break;
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        string breeds;
        cin >> breeds;
        int g = 0, h = 0;
        for (int i = 0; i < n; i++) {
            if (breeds[i] == 'G') {
                g ^= 1 << i;
            }
            else {
                h ^= 1 << i;
            }
        }
        cout << solve_subset(g, n) * solve_subset(h, n) << endl;
    }
}