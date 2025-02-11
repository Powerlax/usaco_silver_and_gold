//
// Created by innav_z3e3dq9 on 2/5/2025.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    int ans = 0;
    while (n != 0) {
        ans++;
        string s = to_string(n);
        int greatest = 0;
        for (int i = 0; i < s.length(); i++) {
            greatest = max(greatest, s[i] - '0');
        }
        n -= greatest;
    }
    cout << ans << endl;
    return 0;
}