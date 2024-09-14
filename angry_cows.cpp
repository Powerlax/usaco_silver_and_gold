//
// Created by innav_z3e3dq9 on 8/1/2024.
//

#include <bits/stdc++.h>
using namespace std;

int first_true(int lo, int hi, function<bool(int)> f) {
    hi++;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (f(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

int last_true(int lo, int hi, int r, function<bool(int, int)> f) {
    lo--;
    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        if (f(mid, r)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    return lo;
}

int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> bales(n);
    for (int i = 0; i<n; i++) {
        cin >> bales[i];
    }
    sort(bales.begin(), bales.end());
    cout << first_true(1, bales[n-1], [&](int r) {
        int loc = last_true(1, bales[n-1], r, [=](int x, int r) {
            while (!bales.empty()) {
                auto it = upper_bound(bales.begin(), bales.end(), x+r);
            }
            return true;
        });
        if (loc == -1) {
            return false;
        }
        return true;
    });
    return 0;
}