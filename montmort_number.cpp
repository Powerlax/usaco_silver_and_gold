//
// Created by innav_z3e3dq9 on 8/31/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int perm1 = 1, perm2 = 0;
    for (int i = 0; i < n; i++) {
        int ans = (long long) i * (perm1 + perm2) % m;
        perm2 = perm1;
        perm1 = ans;
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}