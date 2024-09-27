//
// Created by innav_z3e3dq9 on 9/23/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    vector<int> dp(x + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            if (j - coins[i - 1] >= 0) {
                dp[j] += dp[j - coins[i - 1]];
                dp[j] %= 1000000007;
            }
        }
    }
    cout << dp[x] << '\n';
}