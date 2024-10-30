//
// Created by innav_z3e3dq9 on 10/21/2024.
//

#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<long long>>> dp(17, vector<vector<long long>>(3, vector<long long>(140)));

long long calc_sum(const string &s, const int idx, const int smaller, const int sum) {
    if (idx == s.size()) {
        return sum;
    }
    if (dp[idx][smaller][sum] != -1) {
        return dp[idx][smaller][sum];
    }
    long long ans = 0;
    const int limit = (smaller ? 9 : s[idx] - '0');
    for (int i = 0; i <= limit; i++) {
        ans += calc_sum(s, idx + 1, smaller || (i < s[idx] - '0'), sum + i);
    }
    dp[idx][smaller][sum] = ans;
    return ans;
}

long long solved(const string &s) {
    dp = vector<vector<vector<long long>>>(17, vector<vector<long long>>(3, vector<long long>(140)));
    return calc_sum(s, 0, 0, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        if (a == 0) {
            cout << solved(to_string(b)) << endl;
            continue;
        }
        cout << solved(to_string(b)) - solved(to_string(a - 1)) << endl;
    }
    return 0;
}