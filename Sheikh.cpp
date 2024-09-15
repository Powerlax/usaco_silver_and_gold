//
// Created by innav_z3e3dq9 on 8/15/2024.
//
#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    for (int z = 0; z < t; z++) {
        int n, q;
        cin >> n >> q;
        vector<long long> pref_sum(n + 1);
        vector<long long> pref_xor(n + 1);
        auto cost = [&](int l, int r) {
            return (pref_sum[r] - pref_sum[l - 1]) -
                   (pref_xor[r] ^ pref_xor[l - 1]);
        };
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            pref_sum[i + 1] = x + pref_sum[i];
            pref_xor[i + 1] = x ^ pref_xor[i];
        }
        int L, R;
        cin >> L >> R;
        long long best_cost = cost(1, n);
        int lo = 1, hi = n;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            bool possible = 0;
            for (int i = 1; i + mid - 1 <= n; i++) {
                if (cost(i, i + mid - 1) == best_cost) {
                    possible = 1;
                    break;
                }
            }
            if (possible) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        for (int i = 1; i + lo - 1 <= n; i++) {
            if (cost(i, i + lo - 1) == best_cost) {
                cout << i << ' ' << i + lo - 1 << endl;
                break;
            }
        }
    }
}