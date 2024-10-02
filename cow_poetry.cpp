//
// Created by innav_z3e3dq9 on 9/27/2024.
//

#include <bits/stdc++.h>
using namespace std;
using namespace std;

long long mod_exp(long long a, long long b) {
    if (a == 0) { return 0; }
    long long ret = 1;
    while (b > 0) {
        if (b % 2 == 1) { ret = (ret * a) % 1000000007; }
        a = (a * a) % 1000000007;
        b /= 2;
    }
    return ret;
}

int main() {
    freopen("poetry.in", "r", stdin);
    freopen("poetry.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    vector<long long> count(k + 1, 0);
    vector<vector<long long>> type(n + 1);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        count[a]++;
        type[b].push_back(a);
    }
    vector<int> rhyme(m);
    for (int i = 0; i < m; i++) {
        char a;
        cin >> a;
        rhyme[i] = a - 'A';
    }
    vector<long long> dp(k + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= i; j++) { dp[i] = (dp[i] + (dp[i - j] * count[j])) % 1000000007; }
    }
    vector<long long> total(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < type[i].size(); j++) {
            total[i] = (total[i] + dp[k - type[i][j]]) % 1000000007;
        }
    }
    if (dp[k] == 0) {
        cout << 0;
        return 0;
    }
    sort(rhyme.begin(), rhyme.end());
    vector<int> groups;
    rhyme.push_back(-1);
    int back = 0;
    for (int i = 1; i <= m; i++) {
        if (rhyme[i] != rhyme[i - 1]) {
            groups.push_back(i - back);
            back = i;
        }
    }
    long long ans = 1;
    for (int group : groups) {
        long long curr = 0;
        for (int j = 1; j <= n; j++) {
            curr = (curr + mod_exp(total[j], group)) % 1000000007;
        }
        ans = (ans * curr) % 1000000007;
    }
    cout << ans << endl;
}