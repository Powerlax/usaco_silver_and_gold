//
// Created by innav_z3e3dq9 on 12/29/2024.
//

#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<long long, long long>, int>> all_subsets(const vector<pair<long long, long long>> &dirs) {
    vector<pair<pair<long long, long long>, int>> subset{{}};
    for (const auto &[fst, snd] : dirs) {
        subset.resize(2 * subset.size());
        for (int i = 0; i < subset.size() / 2; i++) {
            subset[i + subset.size() / 2] = {{subset[i].first.first + fst,
         subset[i].first.second + snd}, subset[i].second + 1};
        }
    }
    sort(subset.begin(), subset.end());
    return subset;
}

int main() {
    int n;
    cin >> n;
    pair<long long, long long> goal;
    cin >> goal.first >> goal.second;
    vector<pair<long long, long long>> dirs(n);
    for (auto &d : dirs) {
        cin >> d.first >> d.second;
    }
    vector<pair<pair<long long, long long>, int>> a =
    all_subsets(vector<pair<long long, long long>>(dirs.begin(), dirs.begin() + n / 2));
    vector<pair<pair<long long, long long>, int>> b =
    all_subsets(vector<pair<long long, long long>>(dirs.begin() + n / 2, dirs.end()));
    reverse(b.begin(), b.end());
    vector<long long> ans(n + 1);
    vector<int> with_num;
    pair rest_prev{LLONG_MAX, LLONG_MAX};
    int selection = 0;
    for (const auto &[offset, num] : a) {
        if (const pair rest = {goal.first - offset.first, goal.second - offset.second}; rest != rest_prev) {
            rest_prev = rest;
            with_num = vector<int>(n - n / 2 + 1);
            while (selection < b.size() && b[selection].first > rest) {
                selection++;
            }
            for (; selection < b.size() && b[selection].first == rest; selection++) {
                with_num[b[selection].second]++;
            }
        }
        for (int i = 0; i < with_num.size(); i++) {
            ans[i + num] += with_num[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
}