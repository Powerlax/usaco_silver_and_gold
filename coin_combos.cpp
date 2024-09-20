//
// Created by innav_z3e3dq9 on 9/19/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    vector<long long> dp(x+1);
    dp[0] = 1;
    for (int i = 0; i <= x; i++) {
        for (auto j : coins) {
            if (i-j >= 0) {
                dp[i] += dp[i-j];
                dp[i] %= 1000000007;
            }
        }
    }
    cout << dp[x] << endl;
    return 0;
}