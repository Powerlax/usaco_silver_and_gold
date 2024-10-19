//
// Created by innav_z3e3dq9 on 6/17/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> prefix(n+1);
    prefix[0] = 0;
    for (int i = 1; i<=n; i++) {
        long long temp;
        cin >> temp;
        prefix[i] = prefix[i-1] + temp;
    }
    long long max_arr = prefix[1];
    long long min_arr = prefix[0];
    for (int i = 1; i<=n; i++) {
        max_arr = max(max_arr, prefix[i]-min_arr);
        min_arr = min(min_arr, prefix[i]);
    }
    cout << max_arr;
    return 0;
}