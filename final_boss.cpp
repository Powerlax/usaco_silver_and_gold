//
// Created by innav_z3e3dq9 on 1/19/2025.
//

#include <bits/stdc++.h>
using namespace std;

long long first_true(long long lo, long long hi, function<bool(long long)> f) {
    hi++;
    while (lo < hi) {
        if (const long long mid = lo + (hi - lo) / 2; f(mid)) {
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
    int t;
    cin >> t;
    while (t--) {
        int h, n;
        cin >> h >> n;
        vector<int> damage(n);
        for (int i = 0; i < n; i++) {
            cin >> damage[i];
        }
        vector<int> cooldown(n);
        for (int i = 0; i < n; i++) {
            cin >> cooldown[i];
        }
        cout << first_true(0, LLONG_MAX - 1, [&](const long long turns) {
            long long total_damage = 0;
            for (int i = 0; i < n; i++) {
                total_damage += damage[i] * ((turns / cooldown[i]) + 1);
                if (total_damage >= h || total_damage <= 0) {
                    return true;
                }
            }
            return false;
        }) + 1 << endl;
    }
}