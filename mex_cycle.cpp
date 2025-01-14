//
// Created by innav_z3e3dq9 on 1/8/2025.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        x--;
        y--;
        vector<int> ans(n);
        bool zero = true;
        for (int i = x; i < n; i++) {
            if (zero) {
                ans[i] = 0;
            } else {
                ans[i] = 1;
            }
            zero = !zero;
        }
        for (int i = 0; i < x; i++) {
            if (zero) {
                ans[i] = 0;
            } else {
                ans[i] = 1;
            }
            zero = !zero;
        }
        if (n % 2 == 1 || (x-y) % 2 == 0) {
            ans[x] = 2;
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}