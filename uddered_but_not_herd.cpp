//
// Created by innav_z3e3dq9 on 10/9/2024.
//

#include <bits/stdc++.h>

using namespace std;


int main() {
    string s;
    cin >> s;
    map<char, int> counts;
    for (int i = 0; i < s.length(); i++) {
        counts[s[i]] = 0;
    }
    int count = 0;
    for (auto &c: counts) {
        c.second = count++;
    }
    int n = counts.size();
    vector oc(n,vector<int>(n));
    for (int i = 0; i < s.size()-1; i++) {
        ++oc[counts[s[i]]][counts[s[i+1]]];
    }
    vector dp(1 << n, INT_MAX);
    dp[0] = 1;
    int bits = n/2;
    vector stor1(1<<10, vector<int>(20));
    vector stor2(1<<10, vector<int>(20));
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < 1 << bits; i++) {
            for (int k = 0; k < bits; k++) {
                if (i & 1 << k) {
                    stor1[i][j] += oc[k][j];
                }
            }
        }
        for (int i = 0; i < 1 << (n-bits); i++) {
            for (int k = 0; k < n-bits; k++) {
                if (i & 1 << k) {
                    stor2[i][j] += oc[bits+k][j];
                }
            }
        }
    }
    for (int i = 0; i < 1 << n; i++)
        for (int j = 0; j < n; j++) if (i&1<<j) {
            int sum = dp[i ^ 1 << j];
            sum += stor1[i & ((1 << bits)-1)][j];
            sum += stor2[i >> bits][j];
            dp[i] = min(dp[i], sum);
        }
    cout << dp[(1 << n)-1] << endl;
}