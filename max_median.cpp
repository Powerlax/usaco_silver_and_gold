//
// Created by innav_z3e3dq9 on 7/30/2024.
//

#include <bits/stdc++.h>
using namespace std;

int last_true(int low, int high, function<bool(int)> f) {
    low--;
    while (low< high) {
        int mid = low + (high - low + 1) / 2;
        if (f(mid)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int size;
    int max_ops;
    cin >> size >> max_ops;
    vector<int> arr(size);
    for (int &i : arr) { cin >> i; }
    sort(arr.begin(), arr.end());
    cout << last_true(1, 2e9, [&](int x) {
        long long ops_needed = 0;
        for (int i = (size - 1) / 2; i < size; i++) {
            ops_needed += max(0, x - arr[i]);
        }
        return ops_needed <= max_ops;
    }) << endl;
}