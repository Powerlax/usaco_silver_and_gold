//
// Created by innav_z3e3dq9 on 8/1/2024.
//

#include <bits/stdc++.h>
using namespace std;

long long first_true(long long lo, long long hi, function<bool(long long)> f) {
    hi++;
    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        if (f(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
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
    cout << first_true(1, 2e5 * 1e9, [&](long long max) {
        int subs = 0;
        long long curr = 0;
        for (int i = 0; i<n; i++) {
            if (arr[i] > max) {
                return false;
            }
            if ((curr + arr[i]) > max) {
                if (subs == k) {
                    return false;
                }
                subs++;
                curr = 0;
            }
            curr += arr[i];
        }
        if (curr > 0) {
            subs++;
        }
        return subs <= k;
    });
    return 0;
}