//
// Created by innav_z3e3dq9 on 9/24/2024.
//

#include<bits/stdc++.h>
using namespace std;

int main() {
    int q, k;
    cin >> q >> k;
    vector<int> dp(5005);
    dp[0] = 1;
    while (q > 0) {
        q--;
        string s;
        int x;
        cin >> s >> x;
        if (s == "+") {
            for (int i = k; i>=x; i--) {
                dp[i] += dp[i-x];
                dp[i] %= 1000000007;
            }
        } else {
            for (int i = x; i<=k; i++) {
                dp[i] += (1000000007-dp[i-x]);
                dp[i] %= 1000000007;
            }
        }
        cout << dp[k] << endl;
    }
    return 0;
}