//
// Created by innav_z3e3dq9 on 6/19/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("paintbarn.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    int barn_pre[1001][1001];
    for (int i = 0; i<n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        barn_pre[x1][y1]++;
        barn_pre[x2][y1]--;
        barn_pre[x1][y2]--;
        barn_pre[x2][y2]++;
    }
    int count = 0;
    for (int i = 0; i<1000; i++) {
        for (int j = 0; j<1000; j++) {
            if (i > 0) barn_pre[i][j] += barn_pre[i - 1][j];
            if (j > 0) barn_pre[i][j] += barn_pre[i][j - 1];
            if (i > 0 && j > 0) barn_pre[i][j] -= barn_pre[i - 1][j - 1];
            count += barn_pre[i][j] == k;
        }
    }
    freopen("paintbarn.out", "w", stdout);
    cout << count << endl;
    return 0;
}