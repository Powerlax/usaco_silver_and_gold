//
// Created by innav_z3e3dq9 on 10/17/2024.
//

#include <bits/stdc++.h>
using namespace std;

bool check_max(int &a, const int &b) {
    return a < b ? a = b, 1 : false;
}

int main() {
    freopen("pieaters.in", "r", stdin);
    freopen("pieaters.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector mx(n, vector(n, vector<int>(n)));
    vector<int> weight(m), left(m), right(m);
    for (int i = 0; i < m; i++) {
        cin >> weight[i] >> left[i] >> right[i];
        left[i]--, right[i]--;
        for (int j = left[i]; j <= right[i]; j++) {
            check_max(mx[j][left[i]][right[i]], weight[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j >= 0; j--) {
            for (int k = i; k < n; k++) {
                if (j) {
                    check_max(mx[i][j-1][k], mx[i][j][k]);
                }
                if (k < n-1) {
                    check_max(mx[i][j][k+1], mx[i][j][k]);
                }
            }
        }
    }
    vector dp(n, vector<int>(n));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            for (int k = i; k < j; k++) {
                check_max(dp[i][j], dp[i][k] + dp[k+1][j]);
            }
            for (int k = i; k <= j; k++) {
                if (mx[k][i][j]) {
                    int res = mx[k][i][j];
                    if (k > i) {
                        res += dp[i][k-1];
                    }
                    if (k < j) {
                        res += dp[k+1][j];
                    }
                    check_max(dp[i][j], res);
                }
            }
        }
    }
    cout << dp[0][n-1] << endl;
    return 0;
}