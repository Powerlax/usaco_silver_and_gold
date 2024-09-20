//
// Created by innav_z3e3dq9 on 8/13/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> prefix_sum(n+1);
    for (int i = 2; i <= n; i++) {
        int num = i;
        while (num % 2 == 0) {
            prefix_sum[i]++;
            num /= 2;
        }
        prefix_sum[i] += prefix_sum[i - 1];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (prefix_sum[n - 1] - prefix_sum[i] - prefix_sum[n - i - 1] == 0) { ans ^= num; }
    }
    cout << ans;
    return 0;
}