//
// Created by innav_z3e3dq9 on 9/26/2024.
//

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    int sum_elem = n * (n + 1) / 2;
    if (sum_elem & 1) {
        cout << 0 << endl;
        return 0;
    }
    sum_elem /= 2;
    vector<vector<int>> dp(n, vector<int>(sum_elem + 1));
    dp[0][0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= sum_elem; j++) {
            dp[i][j] += dp[i - 1][j];
            int prev = j - i;
            if (prev >= 0) {
              dp[i][j] += dp[i - 1][prev];
            }
            dp[i][j] %= MOD;
        }
    }
    cout << dp[n - 1][sum_elem] << '\n';
}