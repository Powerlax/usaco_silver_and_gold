//
// Created by innav_z3e3dq9 on 10/22/2024.
//

#include <bits/stdc++.h>
using namespace std;

int count_digits(int x) {
    int ans = 0;
    while (x) {
        ans++;
        x /= 10;
    }
    return ans;
}

int main() {
    int n;
    long long a, b;
    cin >> n >> a >> b;
    vector dp(n, vector(n + 1, vector<int>(b + 1)));
    vector<int> digit(n);
    for (int i = 0; i < n; i++) {
        cin >> digit[i];
    }
    for (int i = 0; i < n; i++) {
        dp[i][i][0] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            for (int k = 0; k <= b; k++) {
                dp[i][j + 1][k] += dp[i][j][k], dp[i][j + 1][k] %= 1000000007;
                int addRight = 10 * k + digit[j];
                if (addRight <= b) {
                    dp[i][j + 1][addRight] += dp[i][j][k];
                    dp[i][j + 1][addRight] %= 1000000007;
                }
                int addLeft = pow(10, count_digits(k)) * digit[j] + k;
                if (addLeft <= b) {
                    dp[i][j + 1][addLeft] += dp[i][j][k];
                    dp[i][j + 1][addLeft] %= 1000000007;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = 1; k <= b; k++) {
                dp[i][j][k] += dp[i][j][k - 1];
            }
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        cout << (dp[l][r][b] - dp[l][r][a - 1] + 1000000007) % 1000000007 << endl;
    }
}