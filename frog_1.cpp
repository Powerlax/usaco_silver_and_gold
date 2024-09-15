//
// Created by innav_z3e3dq9 on 9/9/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    map<int, int> costs;
    vector<int> heights;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        heights.push_back(h);
        costs[i] = INT_MAX;
    }
    costs[0] = 0;
    for (int i = 0; i<n-1; i++) {
        costs[i+1] = min(costs[i+1], costs[i] + abs(heights[i]-heights[i+1]));
        if (i+2<n) {
            costs[i+2] = min(costs[i+2], costs[i] + abs(heights[i]-heights[i+2]));
        }
    }
    cout << costs[n-1] << endl;
    return 0;
}