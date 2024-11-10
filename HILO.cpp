//
// Created by innav_z3e3dq9 on 11/9/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> order(n);
    for (int i = 0; i < n; i++) {
        cin >> order[i];
    }
    vector<int> pos(n + 1);
    for (int i = 0; i < n; i++) {
        pos[order[i]] = i;
    }
    map<int, int> existing;
    vector<int> changes(n + 1);
    for (int i = 0; i < n; i++) {
        int num = order[i];
        if (auto upper_iterator = existing.upper_bound(num); upper_iterator != existing.end()) {
            if (upper_iterator == existing.begin()) {
                ++changes[num];
            }
            if (upper_iterator -> second > prev(upper_iterator) -> second) {
                ++changes[num];
            }
        }
        if (pos[num - 1] > pos[num]) {
            --changes[num];
        }
        existing[num] = i;
    }
    int sum = 0;
    for (int i = 0; i < n + 1; i++) {
        sum += changes[i];
        cout << sum << endl;
    }
}