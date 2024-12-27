//
// Created by innav_z3e3dq9 on 12/19/2024.
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
        int n;
        cin >> n;
        vector grid(n, pair(0, 0));
        for (int i = 0; i < n; i++) {
            cin >> grid[i].first;
        }
        for (int i = 0; i < n; i++) {
            cin >> grid[i].second;
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += max(grid[i].first, grid[i].second);
        }
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (sum + min(grid[i].first, grid[i].second) > ans) {
                ans = sum + min(grid[i].first, grid[i].second);
            }
        }
        cout << ans << endl;
    }
    return 0;
}