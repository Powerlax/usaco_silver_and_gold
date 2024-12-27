//
// Created by innav_z3e3dq9 on 7/17/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> tasks;
    for (int i = 0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        tasks.emplace_back(a,b);
    }
    sort(tasks.begin(), tasks.end());
    long long ans = 0;
    long long time = 0;
    for (int i = 0; i<n; i++) {
        time += tasks[i].first;
        ans += (tasks[i].second - time);
    }
    cout << ans << endl;
    return 0;
}