//
// Created by innav_z3e3dq9 on 9/1/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    double ans = 0.0;
    for (double i = 1; i <= k; i++) {
        ans += i * (pow(i/k, n) - pow((i-1)/k, n));
    }
    cout << fixed << setprecision(6) << ans << endl;
    return 0;
}