//
// Created by innav_z3e3dq9 on 12/27/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector a(1005, vector<char>(1005));
        vector<char> layer(4005);
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++) {
                a[i][j] = s[j];
            }
        }
        int ans = 0;
        for (int i = 0; (i + 1) * 2 <= n && (i + 1) * 2 <= m; i++) {
            int pos = 0;
            for (int j = i; j < m - i; j++) {
                layer[pos++] = a[i][j];
            }
            for (int j = i + 1; j < n - i - 1; j++) {
                layer[pos++] = a[j][m - i - 1];
            }
            for (int j = m - i - 1; j >= i; j--) {
                layer[pos++] = a[n - i - 1][j];
            }
            for (int j = n - i - 2; j >= i + 1; j--) {
                layer[pos++] = a[j][i];
            }
            for (int j = 0; j < pos; j++) {
                if (layer[j] == '1' && layer[(j + 1) % pos] == '5' && layer[(j + 2) % pos] == '4' && layer[(j + 3) % pos] == '3') {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}