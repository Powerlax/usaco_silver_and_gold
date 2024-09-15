//
// Created by innav_z3e3dq9 on 9/12/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("time.in", "r", stdin);
    //freopen("time.out", "w", stdout);
    int n, m, c;
    cin >> n >> m >> c;
    int ans = 0;
    vector<vector<int>> adj(n);
    vector<int> gained(n);
    for (int i = 0; i < n; i++) {
        cin >> gained[i];
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
    }
    vector dp(1001, vector<int>(n, -1));
    dp[0][0] = 0;

    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] != -1) {
                for (auto k : adj[j]) {
                    dp[i+1][k] = max(dp[i+1][k], dp[i][j] + gained[k]);
                }
            }
        }
        ans = max(ans, dp[i][0] - (i*i*c));
    }
    cout << ans << endl;
    return 0;
}