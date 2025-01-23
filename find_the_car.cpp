//
// Created by innav_z3e3dq9 on 1/19/2025.
//

#include <bits/stdc++.h>
using namespace std;

struct Speed {
    int pos;
    double speed;
};

bool comp(const Speed &a, const Speed &b) {
    return a.pos < b.pos;
}

int main() {
    ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    //cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k, q;
        cin >> n >> k >> q;
        set<Speed, decltype(comp)*> speeds(comp);
        speeds.insert({0, -1});
        vector<int> pos(k);
        for (int i = 0; i < k; i++) {
            cin >> pos[i];
        }
        vector<int> time(k);
        unordered_map<int, int> mapping;
        for (int i = 0; i < k; i++) {
            cin >> time[i];
            mapping[pos[i]] = time[i];
        }
        int prev_pos = 0, prev_time = 0;
        for (int i = 0; i < k; i++) {
            speeds.insert({pos[i],(static_cast<double>
            (pos[i] - prev_pos)/static_cast<double>(time[i] - prev_time))});
            prev_pos = pos[i];
            prev_time = time[i];
        }
        int a = 0;
        while (q--) {
            int d;
            cin >> d;
            Speed speed = *speeds.upper_bound({d, INT_MAX});
            Speed speed2 = *--speeds.upper_bound({d, INT_MAX});
            const int dist = d - speed2.pos;
            const int ans = mapping[speed2.pos] + static_cast<int>(dist / speed.speed);
            cout << ans << ' ';
        }
        cout << endl;
    }
}