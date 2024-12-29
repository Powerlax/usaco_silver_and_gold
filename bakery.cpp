//
// Created by innav_z3e3dq9 on 12/29/2024.
//

#include <bits/stdc++.h>
using namespace std;

struct Cow {
    long long a, b, c;
};

int first_true(int lo, int hi, function<bool(int)> f) {
    hi++;
    while (lo < hi) {
        const int mid = lo + (hi - lo) / 2;
        if (f(mid)) {
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
        int n, tC, tM;
        cin >> n >> tC >> tM;
        vector<Cow> cows(n);
        for (int i = 0; i < n; i++) {
            cin >> cows[i].a >> cows[i].b >> cows[i].c;
        }
        int a;
        cout << first_true(0, tC+tM-2, [&](const int m) {
            long long low = max(1, tC - m);
            long long high = min(tC + tM - m - 1, tC);
            for (const auto &[a, b, c] : cows) {
                long long d = tC + tM - m;
                if (b - a > 0) {
                    low = max(low, (-c + b * d + (b - a - 1)) / (b - a));
                } else if (a - b > 0) {
                    high = min(high, (c - b * d) / (a - b));
                } else {
                    if (a * d > c) {
                        return false;
                    }
                }
            }
            return low <= high;
        }) << endl;
    }
}