//
// Created by innav_z3e3dq9 on 9/12/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector dp(1e5 + 5, vector(25, vector<int>(3)));
    map<char, int> convert;
    convert['H'] = 0;
    convert['P'] = 1;
    convert['S'] = 2;
    vector<int> fj;
    for (int i = 0; i<n; i++) {
        char a;
        cin >> a;
        fj.push_back(convert[a]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int l = 0; l < 3; l++) {
                if (l == fj[i]) {
                    dp[i][j][l]++;
                }
                dp[i + 1][j + 1][0] = max(dp[i + 1][j + 1][0], dp[i][j][l]);
                dp[i + 1][j + 1][1] = max(dp[i + 1][j + 1][1], dp[i][j][l]);
                dp[i + 1][j + 1][2] = max(dp[i + 1][j + 1][2], dp[i][j][l]);
                dp[i + 1][j][l] = max(dp[i + 1][j][l], dp[i][j][l]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i<3; i++) {
        ans = max(ans, dp[n-1][k][i]);
    }
    cout << ans << endl;
    return 0;
}