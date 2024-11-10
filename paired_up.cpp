//
// Created by innav_z3e3dq9 on 11/9/2024.
//

#include <bits/stdc++.h>
using namespace std;

int k;

int calc_max_cost(vector<pair<int, int>> &cows) {
    const int len = static_cast<int>(cows.size());
    if (!len) return 0;
    vector<pair<int, int>> dp(len + 1);
    dp[len] = {0, INT_MIN};
    for (int i = len - 1; ~i; i--) {
        dp[i] = dp[i + 1];
        const int upper = upper_bound(cows.begin(), cows.end(), make_pair(cows[i].first + k, INT_MAX)) - cows.begin();
        if (i == 0 || i == len - 1 ||
            cows[i + 1].first - cows[i - 1].first <= k || !(len - i & 1))
            dp[i].first = max(dp[i].first, dp[upper].second + cows[i].second);
        if (i == 0 || i == len - 1 ||
            cows[i + 1].first - cows[i - 1].first <= k || (len - i & 1))
            dp[i].second = max(dp[i].second, dp[upper].first + cows[i].second);
    }
    return (len & 1 ? dp[0].second : dp[0].first);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t, n;
    cin >> t >> n >> k;
    vector<pair<int, int>> cows;
    int ans = 0;
    int last = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a - last > k) {
            if (t == 1 && cows.size() % 2 == 1) {
                int min_cost = INT_MAX;
                for (int j = 0; j < cows.size(); j++) {
                    if (!(j & 1) || cows[j+1].first - cows[j-1].second <= k) {
                        min_cost = min(min_cost, cows[j].second);
                    }
                }
                ans += min_cost;
            } else {
                ans += calc_max_cost(cows);
            }
            cows.clear();
        }
        cows.emplace_back(a, b);
        last = a;
    }
    if (t == 1) {
        if (cows.size() & 1) {
            int min_cost = INT_MAX;
            for (int j = 0; j < cows.size(); j++) {
                if (!(j & 1) || cows[j+1].first - cows[j-1].second <= k) {
                    min_cost = min(min_cost, cows[j].second);
                }
            }
            ans += min_cost;
        }
    } else {
        ans += calc_max_cost(cows);
    }
    cout << ans << endl;
    return 0;
}