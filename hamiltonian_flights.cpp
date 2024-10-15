//
// Created by innav_z3e3dq9 on 10/8/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector dp(1<<n, vector<long long>(n));
    dp[1][0] = 1;
    for (int i = 2; i < 1 << n; i++) {
        if ((i & 1 << 0) == 0) {
            continue;
        }
        if (i & 1 << n - 1 && i != (1 << n) - 1) {
            continue;
        }
        for (int j = 0; j < n; j++) {
            if ((i & 1 << j) == 0) {
                continue;
            }
            int previous = i - (1 << j);
            for (auto k : adj[j]) {
                if ((i & 1 << k)) {
                    dp[i][j] += dp[previous][k];
                    dp[i][j] %= 1000000007;
                }
            }
        }
    }
    cout << dp[(1 << n) - 1][(1 << n) - 1] << endl;
    return 0;
}