//
// Created by innav_z3e3dq9 on 10/7/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("nocross.in", "r", stdin);
    freopen("nocross.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> side1(n+1), side2(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> side1[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> side2[i];
    }
    vector dp(n+1, vector<int>(n+1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = max({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]+(abs(side1[i]-side2[j]) <= 4)});
        }
    }
    cout << dp[n][n] << endl;
    return 0;
}