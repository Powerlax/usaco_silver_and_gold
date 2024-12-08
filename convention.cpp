//
// Created by innav_z3e3dq9 on 11/30/2024.
//

#include <bits/stdc++.h>
using namespace std;

int first_true(int lo, int hi, function<bool(int)> f) {
    hi++;
    while (lo < hi) {
        if (const int mid = lo + (hi - lo) / 2; f(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> times(n);
    for (int i = 0; i < n; i++) {
        cin >> times[i];
    }
    sort(times.begin(), times.end());
    cout << first_true(0, 1000000000, [&](const int max_t) {
        int first_cow = 0, busses_used = 0;
        for (int i = 0; i < n;) {
            if (i == first_cow) {
                busses_used++;
            }
            if (times[i] - times[first_cow] > max_t) {
                first_cow = i;
            } else if (i - first_cow + 1 == c) {
                first_cow = ++i;
            } else {
                i++;
            }
        }
        return busses_used <= m;
    }) << endl;
    return 0;
}