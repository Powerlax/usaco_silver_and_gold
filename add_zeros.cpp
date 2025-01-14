//
// Created by innav_z3e3dq9 on 1/9/2025.
//

#include <bits/stdc++.h>
using namespace std;

unordered_map<long long, unordered_set<long long>> dp;
unordered_map<long long, long long> actual_dp;
int ans;

long long dfs(const long long size) {
    if (actual_dp.count(size)) {
        return actual_dp[size];
    }
    if (dp.count(size)) {
        long long best_ans = LLONG_MIN;
        for (const long long i : dp[size]) {
            actual_dp[size + i] = dfs(size + i);
            best_ans = max(best_ans, actual_dp[size + i]);
        }
        return best_ans;
    }
    return size;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        ans = n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        dp.clear();
        for (int i = 1; i < n; i++) {
            dp[a[i] + i].insert(i);
        }
        actual_dp.clear();
        cout << dfs(n) << endl;
    }
    return 0;
}