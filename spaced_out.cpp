//
// Created by innav_z3e3dq9 on 9/21/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector grid(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    int rows_alternate = 0;
    int cols_alternate = 0;
    for (int i = 0; i < n; i++) {
        int sum_even = 0, sum_odd = 0;
        for (int j = 0; j < n; j++) {
            if (j % 2 == 0) {
                sum_even += grid[i][j];
            } else {
                sum_odd += grid[i][j];
            }
        }
        rows_alternate += max(sum_even, sum_odd);
    }
    for (int i = 0; i < n; i++) {
        int sum_even = 0, sum_odd = 0;
        for (int j = 0; j < n; j++) {
            if (j % 2 == 0) {
                sum_even += grid[j][i];
            } else {
                sum_odd += grid[j][i];
            }
        }
        cols_alternate += max(sum_even, sum_odd);
    }
    cout << max(rows_alternate, cols_alternate) << endl;
    return 0;
}