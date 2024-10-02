//
// Created by innav_z3e3dq9 on 10/1/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a, b;
    cin >> a >> b;
    vector dp(a.length()+1, vector<int>(b.length()+1));
    for (int i = 1; i <= b.length(); i++) {
        dp[0][i] = i;
    }
    for (int i = 1; i <= a.length(); i++) {
        dp[i][0] = i;
    }
    for (int i = 1; i <= a.length(); i++) {
        for (int j = 1; j <= b.length(); j++) {
            dp[i][j] = min(dp[i][j-1]+1, min(dp[i-1][j]+1, dp[i-1][j-1]+(a[i-1]==b[j-1]?0:1)));
        }
    }
    cout << dp[a.length()][b.length()] << endl;
    return 0;
}