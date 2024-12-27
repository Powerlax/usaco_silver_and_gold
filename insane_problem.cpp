//
// Created by innav_z3e3dq9 on 12/26/2024.
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
        long long k, l_1, r_1, l_2, r_2;
        cin >> k >> l_1 >> r_1 >> l_2 >> r_2;
        long long k_n = 1, ans = 0;
        for (int n = 0; r_2/k_n >= l_1; n++) {
            ans += max(static_cast<long long>(0),
                min(r_2 / k_n, r_1) -
                   max((l_2 - 1) / k_n + 1, l_1) + 1);
            k_n *= k;
        }
        cout << ans << endl;
    }
}