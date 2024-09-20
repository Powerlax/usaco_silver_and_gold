//
// Created by innav_z3e3dq9 on 9/19/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<long long> dp(x+1, INT_MAX);
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = coins[i-1]; j <= x; j++) {
            dp[j] = min(dp[j], dp[j-coins[i-1]] + 1);
        }
    }
    cout << (dp[x] == INT_MAX ? -1 : dp[x]) << endl;
    return 0;
}