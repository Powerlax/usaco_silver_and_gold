//
// Created by innav_z3e3dq9 on 7/17/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> items;
    for (int i = 0; i<n; i++) {
        int temp;
        cin >> temp;
        items.push_back(temp);
    }
    sort(items.begin(), items.end());
    int ans = 0;
    int i = 0;
    while (i < n && ans + items[i] <= x) {
        ans += items[i];
        i++;
    }
    cout << i << endl;
    return 0;
}