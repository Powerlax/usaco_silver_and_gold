//
// Created by innav_z3e3dq9 on 6/27/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> old(n);
    vector<int> sorted(n);
    unordered_map<int, int> locations;
    for (int i = 0; i<n; i++) {
        int temp;
        cin >> temp;
        old[i] = temp;
        sorted[i] = temp;
    }
    sort(sorted.begin(), sorted.end());
    for (int i = n-1; i>=0; i--) {
        if (auto thing = locations.find(sorted[i]); thing == locations.end()) {
            locations.insert({sorted[i], i});
        }
    }
    int farthest = 0;
    for (int i = n-1; i>=0; i--) {
        farthest = max(farthest, i-locations[i]);
    }
    cout << farthest;
    return 0;
}