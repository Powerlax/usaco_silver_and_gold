//
// Created by innav_z3e3dq9 on 8/2/2024.
//

#include <bits/stdc++.h>
using namespace std;

int last_true(int lo, int hi, function<bool(int)> f) {
    lo--;
    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        //cout << f(mid) << " " << mid << endl;
        if (f(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    return lo;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    cout << last_true(1, n, [&](int x) {
        int less = 0, more = 0;
        for (int i = 0; i<n; i++) {
            if (arr[i] < x) {
                less++;
            } else {
                more++;
            }
        }
        return more = less;
    });
    return 0;
}