//
// Created by innav_z3e3dq9 on 11/16/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    cout << fixed << showpoint << setprecision(1);
    while (t--) {
        double n, h, d, s, p;
        cin >> n >> h >> d >> s >> p;
        double ans = d / s;
        if ((n - (p * ans)) < 0) {
            const double real_healing_rate = h - p;
            if (real_healing_rate <= 0) {
                cout << -1.0 << endl;
            } else {
                ans = ans + (abs(n - (p * ans)) / real_healing_rate);
                cout << ans << endl;
            }
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}
