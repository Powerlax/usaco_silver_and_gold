//
// Created by innav_z3e3dq9 on 1/5/2025.
//

#include <bits/stdc++.h>
using namespace std;

struct Cow {
    int w, x, d;
};

bool comp(const Cow &a, const Cow &b) {
    return a.x < b.x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen("meetings.in", "r", stdin);
    //freopen("meetings.out", "w", stdout);
    int n, l;
    cin >> n >> l;
    vector<Cow> cows(n);
    int total_weight = 0;
    for (int i = 0; i < n; i++) {
        cin >> cows[i].x >> cows[i].w >> cows[i].d;
        total_weight += cows[i].w;
    }
    sort(cows.begin(), cows.end(), comp);
    vector<int> left_cows_pos, right_cows_pos;
    for (int i = 0; i < n; i++) {
        if (cows[i].d == 1) {
            right_cows_pos.push_back(cows[i].x);
        } else {
            left_cows_pos.push_back(cows[i].x);
        }
    }
    vector<pair<int, int>> order;
    for (int i = 0; i < left_cows_pos.size(); i++) {
        order.emplace_back(left_cows_pos[i], cows[i].w);
    }
    for (int i = 0; i < right_cows_pos.size(); i++) {
        order.emplace_back(l - right_cows_pos[i], cows[i + left_cows_pos.size()].w);
    }
    sort(order.begin(), order.end());
    int t = -1;
    for (auto &[pos, weight] : order) {
        total_weight -= weight * 2;
        if (total_weight <= 0) {
            t = pos;
            break;
        }
    }
    //cout << t << endl;
    queue<int> positions;
    int meetings = 0;
    for (int i = 0; i < n; i++) {
        if (cows[i].d == -1) {
            while (!positions.empty() && positions.front() + 2 * t < cows[i].x) {
                positions.pop();
            }
            meetings += static_cast<int>(positions.size());
        } else {
            positions.push(cows[i].x);
        }
    }
    cout << meetings << endl;
    return 0;
}