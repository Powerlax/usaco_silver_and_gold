//
// Created by innav_z3e3dq9 on 9/17/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<long long> dp(n+1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i-j >= 0) {
                dp[i] += dp[i-j];
            }
        }
        dp[i] %= 1000000007;
    }
    cout << dp[n] << endl;
    return 0;
}