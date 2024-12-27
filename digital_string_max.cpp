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
        string s;
        cin >> s;
        const int n = static_cast<int>(s.length());
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = s[i] - '0';
        }
        ans.push_back(-1);
        for (int i = 0; i < n; i++) {
            int max_pos = n;
            if (n - 9 > i) {
                for (int j = i; j < i + 9; j++) {
                    if (ans[j] - (j - i) > ans[max_pos] - (max_pos - i)) {
                        max_pos = j;
                    }
                }
            } else {
                for (int j = i; j < n; j++) {
                    if (ans[j] - (j - i) > ans[max_pos] - (max_pos - i)) {
                        max_pos = j;
                    }
                }
            }
            for (int j = max_pos; j > i; j--) {
                swap(ans[j], ans[j - 1]);
                ans[j - 1]--;
            }
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i];
        }
        cout << endl;
    }
}