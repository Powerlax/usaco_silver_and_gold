//
// Created by innav_z3e3dq9 on 6/24/2024.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<bitset<2001>> grid(2001);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char a;
            cin >> a;
            grid[i][j] = (a == '1');
        }
    }
    vector<vector<int>> pref(2001, vector<int>(2001));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
            if (grid[i][j]) {
                if ((!grid[i - 1][j]) && (!grid[i][j - 1])) {
                    pref[i][j]++;
                }
                if ((grid[i - 1][j]) && (grid[i][j - 1])) {
                    pref[i][j]--;
                }
            }
        }
    }
    vector<vector<int>> horpref(2001, vector<int>(2001));
    vector<vector<int>> verpref(2001, vector<int>(2001));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            horpref[i][j] = horpref[i][j - 1];
            verpref[i][j] = verpref[i - 1][j];
            if (grid[i][j]) {
                horpref[i][j] += !grid[i][j - 1];
                verpref[i][j] += !grid[i - 1][j];
            }
        }
    }
    for (int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int ans = grid[a][b];
        ans += horpref[a][d] - horpref[a][b];
        ans += verpref[c][b] - verpref[a][b];
        ans += pref[c][d] - pref[a][d] - pref[c][b] + pref[a][b];
        cout << ans << endl;
    }
    return 0;
}