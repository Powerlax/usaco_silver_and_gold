//
// Created by innav_z3e3dq9 on 9/16/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> log(n);
    for (int i = 0; i < n; i++) {
        cin >> log[i];
    }
    vector ans(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (j > 0) {
                ans[i][j] = ans[i][j-1] + (log[j] == j-i ? 0:1);
            } else {
                ans[i][j] = log[j] == j-i ? 0:1;
            }
        }
    }
    vector dp(n+1, vector(n, INT_MAX));
    for (int i = 1; i <= n; i++) {
        for (int j = i-1; j < n; j++) {
            if (j == 0) {
                if (log[j] == 0) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = 1;
                }
            }
            if (dp[i][j-1] != INT_MAX) {
                dp[i][j] = dp[i][j-1] + 1;
            }
            if (log[j] && dp[i-1][j-1] != INT_MAX) {
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 1);
            }
            if (j - log[j] - 1 >= 0 && dp[i - 1][j - log[j] - 1] != INT_MAX) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - log[j] - 1] + ans[j - log[j]][j]);
            }
            if (j - log[j] == 0 && i == 1) {
                dp[i][j] = min(dp[i][j], ans[j - log[j]][j]);
            }
        }
    }
    for (int i = 1; i <= n-1; i++) {
        cout << dp[i][n - 1] << endl;
    }
    int a = 0;
    for (int i = 0; i < n; i++) {
        if (log[i] == 0) {
            a++;
        }
    }
    cout << n-a << endl;
    return 0;
}