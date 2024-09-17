//
// Created by innav_z3e3dq9 on 9/15/2024.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("cbarn2.in", "r", stdin);
    freopen("cbarn2.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    deque<int> rooms(n);
    for (int i = 0; i < n; i++) {
        cin >> rooms[i];
    }
    long long ans = INT64_MAX;
    for (int i = 0; i < n; i++) {
        vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, INT64_MAX));
        dp[0][n] = 0;
        for (int j = 1; j <= k; j++) {
            for (int l = 0; l < n; l++) {
                long long partial_dist = 0;
                for (int m = l + 1; m <= n; m++) {
                    partial_dist += rooms[m - 1] * (m - l - 1);
                    long long new_dist = dp[j - 1][m];
                    if (new_dist < INT64_MAX) {
                        new_dist += partial_dist;
                    }
                    dp[j][l] = min(dp[j][l], new_dist);
                }
            }
        }
        ans = min(ans, dp[k][0]);
        int first_room = rooms.front();
        rooms.pop_front();
        rooms.push_back(first_room);
    }
    cout << ans << endl;
}