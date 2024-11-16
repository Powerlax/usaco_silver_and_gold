//
// Created by innav_z3e3dq9 on 8/17/2024.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> ranges;
    for (int i = 0; i<n; i++) {
        vector<int> range;
        for (int j = 0; j<n-i; j++) {
            int temp;
            cin >> temp;
            range.push_back(temp);
        }
        ranges.push_back(range);
    }
    vector<int> ans(n);
    ans[n-1] = 0;
    for (int i = n-2; i>=0; i--) {
        ans[i] = ans[i+1] + ranges[i][1];
        int minAns = ans[i], maxAns = ans[i];
        for (int j = i+1; j < n; j++) {
            minAns = min(minAns, ans[j]);
            maxAns = max(maxAns, ans[j]);
            if (maxAns-minAns != ranges[i][j - i]) {
                ans[i] = ans[i+1] - ranges[i][1];
                break;
            }
        }
    }
    for (int i = 0; i<n-1; i++) {
        cout << ans[i]-ans[0]+1 << ' ';
    }
    cout << ans[n-1]-ans[0]+1 << endl;
    return 0;
}
