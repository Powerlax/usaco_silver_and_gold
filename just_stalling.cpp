//
// Created by innav_z3e3dq9 on 9/5/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> heights(n), limits(n), valid(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> limits[i];
    }
    sort(heights.begin(), heights.end());
    sort(limits.begin(), limits.end());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (heights[i] <= limits[j]) {
                valid[i]++;
            }
        }
    }
    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans *= valid[i] - (n-i-1);
    }
    cout << ans << endl;
    return 0;
}