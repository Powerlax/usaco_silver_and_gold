//
// Created by innav_z3e3dq9 on 9/26/2024.
//

#include <bits/stdc++.h>
using namespace std;

struct Cow {
    int weight, talent;
};

int main() {
    freopen("talent.in", "r", stdin);
    freopen("talent.out", "w", stdout);
    int n, w;
    cin >> n >> w;
    vector<Cow> cows(n);
    for (int i = 0; i < n; i++) {
        cin >> cows[i].weight >> cows[i].talent;
    }
    vector dp(1000010, 1000000000);
    dp[0] = 0;
    for (int i = 0; i<n; i++) {
        for (int j = 250000; j >= 0; j--) {
            if (dp[j] != 1000000000) {
                dp[j + cows[i].talent] = min(dp[j + cows[i].talent], dp[j] + cows[i].weight);
            }
        }
    }
    double ans = 0;
    for (double i = dp.size()-1; i >= 0; i--) {
        if ((dp[i] >= w) && ((i / dp[i]) > ans)) {
            ans = i / dp[i];
        }
    }
    cout << (int)(ans*1000) << endl;
    return 0;
}

