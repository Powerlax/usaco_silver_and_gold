//
// Created by innav_z3e3dq9 on 8/14/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        string s;
        cin >> s;
        int xor0 = 0, xor1 = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                xor0 = xor0 ^ arr[i];
            } else {
                xor1 = xor1 ^ arr[i];
            }
        }
        vector<int> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] ^ arr[i - 1];
        }
        int q;
        cin >> q;
        while (q--) {
            int type;
            cin >> type;
            if (type == 1) {
                int x, y;
                cin >> x >> y;
                int mid = prefix[y] ^ prefix[x - 1];
                xor0 ^= mid;
                xor1 ^= mid;
            } else if (type == 2) {
                int x;
                cin >> x;
                if (x == 0) cout << xor0;
                else cout << xor1;
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}