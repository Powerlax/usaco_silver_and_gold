//
// Created by innav_z3e3dq9 on 11/24/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("walk.in", "r", stdin);
    freopen("walk.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    const long long ans = static_cast<long long>(2019201997) - static_cast<long long>(48) * n - static_cast<long long>(84) * (k - static_cast<long long>(1));
    cout << ans << endl;
}