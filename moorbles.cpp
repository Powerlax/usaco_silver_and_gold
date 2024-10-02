//
// Created by innav_z3e3dq9 on 9/28/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector deltas(m, vector(2, 10000));
        for (int j = 0; j < m; j++) {
            for (int u = 0; u < k; u++) {
                int x;
                cin >> x;
                deltas[j][x % 2] = min(deltas[j][x % 2], x);
                deltas[j][(x + 1) % 2] = min(deltas[j][(x + 1) % 2], -x);
            }
        }
        vector bounds(m + 1, 0);
        for (int j = m - 1; j >= 0; j--) {
            bounds[j] = max(0, bounds[j + 1] - max(deltas[j][0], deltas[j][1]));
        }
        if (n <= bounds[0]) {
            cout << -1 << endl;
        } else {
            string result;
            for (int j = 0; j < m; j++) {
                if (n + deltas[j][0] > bounds[j + 1]) {
                    n += deltas[j][0];
                    result += "Even ";
                } else {
                    n += deltas[j][1];
                    result += "Odd ";
                }
            }
            result.erase(result.end() - 1);
            cout << result << endl;
        }
    }
    return 0;
}