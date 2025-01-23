//
// Created by innav_z3e3dq9 on 1/17/2025.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int ans = 0;
        for (int c = 1; c < x; c++) {
            for (int b = 1; b <= (n / c); b++) {
                const int a = x - b - c;
                if (a + b + c > x) {
                    continue;
                }
                if ((a * b) + (a * c) + (b * c) > n) {
                    continue;
                }
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}