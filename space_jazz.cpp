//
// Created by innav_z3e3dq9 on 10/14/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string music;
    cin >> music;
    vector dp(music.length()+2, vector<int>(music.length()+2));
    for (int j = 0; j <= music.size(); j++) {
        for (int i = 0; i < music.size() - j; i++) {
            dp[i][i + j] = dp[i + 1][i + j] + 1;
            for (int k = i + 1; k <= i + j; k++) {
                if (music[k] == music[i]) {
                    dp[i][i + j] = min(dp[i][i + j], dp[i + 1][k - 1] + dp[k + 1][i + j]);
                }
            }
        }
    }
    cout << dp[0][music.size()-1] << endl;
    return 0;
}