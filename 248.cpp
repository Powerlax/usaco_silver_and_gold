//
// Created by innav_z3e3dq9 on 10/15/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("248.in", "r", stdin);
    freopen("248.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> game(n);
    for (int i = 0; i < n; i++) {
        cin >> game[i];
    }
    vector dp(n, vector(n, -1));
    int ans = 0;
    for (int i = n-1; i >= 0; i--) {
        dp[i][i] = game[i];
        for (int j = i; j < n; j++) {
            for (int k = i; k < j; k++) {
                if (dp[i][k] != -1 && dp[i][k] == dp[k+1][j]) {
                    dp[i][j] = dp[i][k] + 1;
                }
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}