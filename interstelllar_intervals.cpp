//
// Created by innav_z3e3dq9 on 2/4/2025.
//

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<long long> dp(n);
    dp[0] = 1;
    vector<int> r(n + 1);
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++){
        char c;
        cin >> c;
        r[i] = (c == 'R') + r[i - 1];
        b[i] = (c == 'B') + b[i - 1];
        if (c != 'R' && c != 'B') {
            dp[i] = dp[i - 1];
        }
        for (int x = 1; i - 2 * x + 1 >= 1; x++) {
            if (b[i - x] - b[i - 2 * x] == 0 and r[i] - r[i - x] == 0) {
                dp[i] = (dp[i] + dp[i - 2 * x]) % static_cast<long long>(1e9 + 7);
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}