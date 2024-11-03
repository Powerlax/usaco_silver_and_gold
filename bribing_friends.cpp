//
// Created by innav_z3e3dq9 on 11/3/2024.
//

#include <bits/stdc++.h>
using namespace std;

struct Friend {
    int discount, popularity, cost;
};

bool comp(Friend &a, Friend &b) {
    if (a.discount == b.discount) {
        if (a.popularity == b.popularity) {
            return a.cost < b.cost;
        }
        return a.popularity < b.popularity;
    }
    return a.discount < b.discount;
}

void set_max(int &a, int b) {
    if (b > a) a = b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b;
    cin >> n >> a >> b;
    vector<Friend> cows(n);
    for (int i = 0; i < n; i++) {
        cin >> cows[i].popularity >> cows[i].cost >> cows[i].discount;
    }
    vector dp(n+1, vector(2*n, -1));
    sort(cows.begin(), cows.end(), comp);
    dp[0][a + b] = 0;
    for (int i = 0; i < n; ++i) {
        auto [discount, popularity, cost] = cows[i];
        for (int j = 0; j <= a + b; ++j) {
            if (dp[i][j] == -1) {
                continue;
            }
            set_max(dp[i + 1][j], dp[i][j]);
            if (j - cost * discount >= a) {
                set_max(dp[i + 1][j - cost * discount], dp[i][j] + popularity);
            } else if (j > a) {
                int cost_left = cost - (j - a) / discount;
                if (a - cost_left >= 0)
                    set_max(dp[i + 1][a - cost_left], dp[i][j] + popularity);
            } else if (j <= a && j - cost >= 0) {
                set_max(dp[i + 1][j - cost], dp[i][j] + popularity);
            }
        }
    }
    cout << *max_element(dp[n].begin(), dp[n].end()) << endl;
    return 0;
}