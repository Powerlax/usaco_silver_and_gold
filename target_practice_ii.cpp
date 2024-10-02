//
// Created by innav_z3e3dq9 on 9/28/2024.
//

#include <bits/stdc++.h>
using namespace std;

long long lower_cow(vector<pair<int, int>> &needs_pos, vector<int> &pos_slopes) {
    sort(pos_slopes.begin(), pos_slopes.end(), greater<>());
    long long ans = INT64_MAX;
    for (auto s : pos_slopes) {
        long long best_y = -INT64_MAX;
        int correct_index = -1;
        for (int i = 0; i < needs_pos.size(); i++) {
            if (needs_pos[i].second - needs_pos[i].first * s > best_y) {
                best_y = needs_pos[i].second - needs_pos[i].first * s;
                correct_index = i;
            }
            ans = min(ans, best_y);
        }
        needs_pos.erase(needs_pos.begin() + correct_index);
    }
    return ans;
}

long long upper_cow(vector<pair<int, int>> &needs_neg, vector<int> &neg_slopes) {
    for (auto &i : needs_neg) {
        i.second = -i.second;
    }
    for (int &neg_slope : neg_slopes) {
        neg_slope = -neg_slope;
    }
    return -lower_cow(needs_neg, neg_slopes);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, x1;
        cin >> n >> x1;
        vector<int> with_x1;
        vector<pair<int, int>> needs_pos;
        vector<pair<int, int>> needs_neg;
        for (int i = 0; i < n; i++) {
            int y1, y2, x2;
            cin >> y1 >> y2 >> x2;
            with_x1.push_back(y1);
            with_x1.push_back(y2);
            needs_pos.emplace_back(x2, y1);
            needs_neg.emplace_back(x1, y2);
        }
        vector<int> slopes(n*4);
        for (int i = 0; i < n*4; i++) {
            cin >> slopes[i];
        }
        vector<int> pos_slopes, neg_slopes;
        for (auto s : slopes) {
            if (s < 0) {
                neg_slopes.push_back(s);
            } else {
                pos_slopes.push_back(s);
            }
        }
        if (neg_slopes.size() < n || pos_slopes.size() < n) {
            cout << -1 << endl;
            continue;
        }
        sort(with_x1.begin(), with_x1.end());
        for (auto y : with_x1) {
            if (needs_neg.size() < neg_slopes.size()) {
                needs_neg.emplace_back(x1, y);
            } else {
                needs_pos.emplace_back(x1, y);
            }
        }
        long long larger = upper_cow(needs_neg, neg_slopes);
        long long smaller = lower_cow(needs_pos, pos_slopes);
        cout << larger-smaller << endl;
    }
    return 0;
}