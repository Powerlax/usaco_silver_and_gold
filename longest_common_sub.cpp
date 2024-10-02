//
// Created by innav_z3e3dq9 on 10/1/2024.
//

#include <bits/stdc++.h>
using namespace std;

int solve(string a, string b) {
    vector dp(a.length()+1, vector<int>(b.length()+1));
    for (int i = 1; i <= a.length(); i++) {
        for (int j = 1; j <= b.length(); j++) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[a.length()][b.length()];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string a, b;
    cin >> a >> b;
    cout << solve(a, b) << endl;
    return 0;
}