//
// Created by innav_z3e3dq9 on 2/5/2025.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector dp(n + 1, vector<int>(x + 1));
    vector<pair<int, int>> books(n);
    for (int i = 0; i < n; i++) {
        cin >> books[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> books[i].second;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            dp[i][j] = dp[i - 1][j];
            if (const int best = j - books[i - 1].first; best >= 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][best] + books[i - 1].second);
            }
        }
    }
    cout << dp[n][x] << endl;
    return 0;
}
