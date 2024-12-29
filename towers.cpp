//
// Created by innav_z3e3dq9 on 7/18/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    multiset<int> towers;
    for (int i = 0; i<n; i++) {
        int next;
        cin >> next;
        auto tower = towers.upper_bound(next);
        if (tower != towers.end()) {
            towers.erase(tower);
        }
        towers.insert(next);
    }
    cout << towers.size() << endl;
    return 0;
}