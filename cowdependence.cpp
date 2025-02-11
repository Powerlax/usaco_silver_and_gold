//
// Created by innav_z3e3dq9 on 2/4/2025.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    map<int, set<int>> positions;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (positions.count(a) == 0) {
            positions[a] = set<int>();
        }
        positions[a].insert(i);
    }
    for (int x = 1; x <= n; x++) {
        int ans = 0;
        for (auto &position : positions) {
            set<int> type = position.second;
            auto it2 = type.begin();
            while (it2 != type.end()) {
                auto it3 = lower_bound(it2, type.end(), *it2 + x);
                if (it3 == type.end()) {
                    ans++;
                    break;
                } else if (*it3 > *it2 + x) {
                    ans++;
                    ++it2;
                } else if (*it3 == *it2 + x) {
                    ans++;
                    it2 = it3;
                    ++it2;
                }
            }
        }
        cout << ans << endl;
    }
}