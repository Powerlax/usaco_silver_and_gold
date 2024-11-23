//
// Created by innav_z3e3dq9 on 11/23/2024.
//

#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> dp;
vector<vector<int>> adj;

void dfs(const int node, const int parent) {
    for (const int &i : adj[node]) {
        if (i != parent) {
            dfs(i, node);
            dp[node][0] *= dp[i][1] + dp[i][2];
            dp[node][1] *= dp[i][0] + dp[i][2];
            dp[node][2] *= dp[i][0] + dp[i][1];
            dp[node][0] %= 1000000007;
            dp[node][1] %= 1000000007;
            dp[node][2] %= 1000000007;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("barnpainting.in", "r", stdin);
    freopen("barnpainting.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    adj.resize(n+1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dp = vector(n+1, vector<long long>(3));
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 1, dp[i][1] = 1, dp[i][2] = 1;
    }
    while (m--) {
        int b, c;
        cin >> b >> c;
        dp[b][0] = 0;
        dp[b][1] = 0;
        dp[b][2] = 0;
        dp[b][c - 1] = 1;
    }
    dfs(1, 0);
    cout << (dp[1][0] + dp[1][1] + dp[1][2]) % 1000000007 << endl;
}