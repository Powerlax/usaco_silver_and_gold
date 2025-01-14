//
// Created by innav_z3e3dq9 on 12/12/2024.
//

#include <bits/stdc++.h>
using namespace std;

int n, l;
vector<int> w, x, d;

bool comp(const int i, const int j) {
    return x[i] < x[j];
}

int getTime() {
    vector<int> left, right;
    for (int i = 0; i < n; i++) {
        if (d[i] == -1) {
            left.push_back(x[i]);
        } else {
            right.push_back(x[i]);
        }
    }
    vector<pair<int, int>> v;
    for (int i = 0; i < left.size(); i++) {
        v.emplace_back(left[i], w[i]);
    }
    for (int i = 0; i < right.size(); i++) {
        v.emplace_back(l - right[i], w[left.size() + i]);
    }
    sort(v.begin(), v.end());
    int tot = 0;
    for (auto [fst, snd] : v) {
        tot += snd;
    }
    for (auto [fst, snd] : v) {
        tot -= 2 * snd;
        if (tot <= 0) {
            return fst;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("meetings.in", "r", stdin);
    freopen("meetings.out", "w", stdout);
    cin >> n >> l;
    w.resize(n);
    x.resize(n);
    d.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> x[i] >> d[i];
    }
    vector<int> speeds(n);
    iota(speeds.begin(), speeds.end(), 0);
    sort(speeds.begin(), speeds.end(), comp);
    vector<int> speed_w, speed_x, speed_d;
    for (const int i : speeds) {
        speed_w.push_back(w[i]);
        speed_x.push_back(x[i]);
        speed_d.push_back(d[i]);
    }
    swap(w, speed_w);
    swap(x, speed_x);
    swap(d, speed_d);
    const long int t = getTime();
    queue<int> frontier;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (d[i] == -1) {
            while (!frontier.empty() && frontier.front() + 2 * t < x[i]) {
                frontier.pop();
            }
            ans += static_cast<int>(frontier.size());
        } else {
            frontier.push(x[i]);
        }
    }
    cout << ans << endl;
}