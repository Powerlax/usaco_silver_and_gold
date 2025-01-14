//
// Created by innav_z3e3dq9 on 1/9/2025.
//

#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string buf;
        cin >> buf;
        if (n == 1) {
            cout << "1" << endl;
            continue;
        }
        string s = buf;
        int count = 0;
        for (const auto x : s) {
            if (x == '1') {
                count++;
            }
        }
        int left = 1;
        int right = count + 1;
        while (right - left > 1) {
            const int mid = (left + right) / 2;
            int k = mid;
            vector<int> used(n);
            for (int i = n - 1; i >= 0; i--) {
                if (k > 0 && s[i] == '1') {
                    used[i] = 1;
                    k--;
                }
            }
            int curr = 0;
            bool can = true;
            for (int i = 0; i < n; i++) {
                if (used[i]) {
                    curr--;
                    if (curr < 0) {
                        can = false;
                    }
                } else {
                    curr++;
                }
            }
            if (can) {
                left = mid;
            } else {
                right = mid;
            }
        }
        long long ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1' && left > 0) {
                left--;
            } else {
                ans += i + 1;
            }
        }
        cout << ans << endl;
    }
}