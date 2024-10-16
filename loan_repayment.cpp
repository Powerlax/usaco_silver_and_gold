//
// Created by innav_z3e3dq9 on 8/1/2024.
//

#include <bits/stdc++.h>
using namespace std;

long long last_true(long long lo, long long hi, const function<bool(long long)>& f) {
    lo--;
    while (lo < hi) {
        long long mid = lo + (hi - lo + 1) / 2;
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
    freopen("loan.in", "r", stdin);
    freopen("loan.out", "w", stdout);
    long long n, k, m;
    cin >> n >> k >> m;
    cout << last_true(1, n, [&](long long x){
        long long days = k;
        long long g = 0;
        while (days > 0 && g < n) {
            long long y = (n - g) / x;
            if (y < m) {
                long long leftover = ((n - g) + (m - 1)) / m;
                return leftover <= days;
            }
            long long num_days = std::min(((n - (x * y)) - g) / y + 1, days);
            g += y * num_days;
            days -= num_days;
        }
        return g >= n; 
    });
    return 0;
}