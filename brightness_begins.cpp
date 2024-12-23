//
// Created by innav_z3e3dq9 on 12/19/2024.
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
        long long k;
        cin >> k;
        cout << k + static_cast<int>(sqrtl(k) + 0.5) << endl;
    }
    return 0;
}