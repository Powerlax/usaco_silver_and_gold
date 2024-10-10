//
// Created by innav_z3e3dq9 on 7/23/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);
    int c, n;
    cin >> c >> n;
    multiset<int> times;
    for (int i = 0; i<c; i++) {
        int time;
        cin >> time;
        times.insert(time);
    }
    vector<pair<int, int>> cows;
    for (int i = 0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        cows.emplace_back(a, b);
    }
    sort(cows.begin(), cows.end());
    int ans = 0;
    for (int i = 0; i<n; i++) {
        auto it = times.lower_bound(cows[i].first);
        if (it != times.end() && *it <= cows[i].second) {
            ans++;
            times.erase(it);
        }
    }
    cout << ans << endl;
    return 0;
}