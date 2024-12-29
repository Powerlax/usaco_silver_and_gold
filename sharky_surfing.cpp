//
// Created by innav_z3e3dq9 on 12/27/2024.
//

#include <bits/stdc++.h>
using namespace std;

struct PowerUp {
    int pos, boost;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m, l;
        cin >> n >> m >> l;
        vector<pair<int, int>> hurdles;
        hurdles.emplace_back(-1, -1);
        for (int i = 0; i < n; i++) {
            int L, R;
            cin >> L >> R;
            if (R - L > hurdles.back().second - hurdles.back().first) {
                hurdles.emplace_back(L, R);
            }
        }
        hurdles.erase(hurdles.begin());
        n = static_cast<int>(hurdles.size());
        deque<PowerUp> power_ups;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            power_ups.push_back({a, b});
        }
        int ans = 0;
        int jump = 1;
        bool solved = true;
        priority_queue<int> pq;
        for (auto [left, right] : hurdles) {
            while (!power_ups.empty() && power_ups.front().pos < left) {
                pq.push(power_ups.front().boost);
                power_ups.pop_front();
            }
            while (jump < right - left + 2) {
                if (pq.empty()) {
                    solved = false;
                    break;
                }
                jump += pq.top();
                ans++;
                pq.pop();
            }
            if (!solved) {
                break;
            }
        }
        if (solved) {
            cout << ans << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}