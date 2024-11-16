//
// Created by innav_z3e3dq9 on 11/14/2024.
//

#include <bits/stdc++.h>
using namespace std;

vector<int> dp;
vector<vector<int>> adj;
int n;

int get_num_paths(int node) {
    if (node == n-1) {
        return 1;
    }
    if (dp[node] != -1) {
        return dp[node];
    }
    int sum = 0;
    for (int i : adj[node]) {
        sum += get_num_paths(i);
        sum %= 1000000007;
    }
    dp[node] = sum;
    return dp[node];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int m;
    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
    }
    dp.resize(n);
    fill(dp.begin(), dp.end(), -1);
    cout << get_num_paths(0) << endl;
    return 0;
}