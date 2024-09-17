//
// Created by innav_z3e3dq9 on 9/15/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<int> snakes(n+1);
    for (int i = 1; i < n+1; i++) {
        cin >> snakes[i];
    }
    vector dp(n+1, vector<int>(k+1));
    int max_group = -1;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        max_group = max(max_group, snakes[i]);
        dp[i][0] = max_group*i;
        for (int j = 1; j <= k; j++) {
            dp[i][j] = INT_MAX;
            int net_size = snakes[i];
            for (int a = i-1; a>=0; a--) {
                dp[i][j] = min(dp[i][j], dp[a][j-1]+net_size*(i-a));
                net_size = max(net_size, snakes[a]);
            }
        }
        ans += snakes[i];
    }
    cout << dp[n][k] - ans << endl;
    return 0;
}