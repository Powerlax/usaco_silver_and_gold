//
// Created by innav_z3e3dq9 on 11/30/2024.
//
#include <bits/stdc++.h>
using namespace std;

struct Log {
    int day, cow, change;
};

bool comp(const Log &a, const Log &b) {
    return a.day < b.day;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    int n;
    int g;
    cin >> n >> g;
    vector<Log> logs(n);
    map<int, int> cows;
    for (int i = 0; i < n; i++) {
        cin >> logs[i].day >> logs[i].cow >> logs[i].change;
        cows[logs[i].cow] = g;
    }
    sort(logs.begin(), logs.end(), comp);
    map<int, int> milk{{g, n}};
    int changeAmt = 0;
    for (Log log : logs) {
        int milk_amount = cows[log.cow];
        const bool was_top = milk_amount == milk.rbegin()->first;
        const int prev_count = milk[milk_amount];
        milk[milk_amount]--;
        if (milk[milk_amount] == 0) {
            milk.erase(milk_amount);
        }
        milk_amount += log.change;
        cows[log.cow] = milk_amount;
        milk[milk_amount]++;
        const bool is_top = milk_amount == milk.rbegin()->first;
        const int curr = milk[milk_amount];
        if (was_top) {
            if (is_top && curr == prev_count) {
                continue;
            }
            changeAmt++;
        } else if (is_top) {
            changeAmt++;
        }
    }
    cout << changeAmt << endl;
    return 0;
}