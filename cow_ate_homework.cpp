//
// Created by innav_z3e3dq9 on 12/12/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("homework.in", "r", stdin);
    freopen("homework.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> scores(n);
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }
    vector<long long> suffix_sum(n + 1);
    vector suffix_min(n + 1, INT_MAX);
    for (int i = n - 1; i >= 0; i--) {
        suffix_sum[i] = suffix_sum[i + 1] + scores[i];
        suffix_min[i] = min(suffix_min[i + 1], scores[i]);
    }
    double max_average = -1;
    vector<int> ans;
    for (int k = 1; k <= n - 2; k++) {
        const int count = n - k - 1;
        if (count <= 0) {
            continue;
        }
        const double average = static_cast<double>(suffix_sum[k] - suffix_min[k]) / count;
        if (average > max_average) {
            max_average = average;
            ans.clear();
            ans.push_back(k);
        } else if (average == max_average) {
            ans.push_back(k);
        }
    }
    for (const int i : ans) {
        cout << i << endl;
    }
    return 0;
}