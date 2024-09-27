//
// Created by innav_z3e3dq9 on 9/26/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);
    int t, a, b;
    cin >> t >> a >> b;
    vector dp(t+1, vector<bool>(2));
    dp[0][0] = true;
    for (int i = 0; i <= t; i++) {
        if (i-a >= 0) {
            dp[i][0] = dp[i][0] || dp[i-a][0];
        }
        if (i-b >= 0) {
            dp[i][0] = dp[i][0] || dp[i-b][0];
        }
        dp[i/2][1] = dp[i/2][1] || dp[i][0];
    }
    for (int i = 0; i <= t; i++) {
        if (i-a >= 0) {
            dp[i][1] = dp[i][1] || dp[i-a][1];
        }
        if (i-b >= 0) {
            dp[i][1] = dp[i][1] || dp[i-b][1];
        }
    }
    for (int i = t; i >= 0; i--) {
        if (dp[i][0] || dp[i][1]) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}
