//
// Created by innav_z3e3dq9 on 8/15/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    vector<long long> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    long long ans = 0;
    for (long long i = 1; i < (1 << k); i++) {
        long long prime_product = 1;
        for (long long j = 0; j < k; j++) {
            if (i & (1 << j)) {
                if (prime_product > n / a[j]) {
                    prime_product = n + 1;
                    break;
                }
                prime_product *= a[j];
            }
        }
        if (__builtin_popcount(i) % 2) {
            ans += n / prime_product;
        } else {
            ans -= n / prime_product;
        }
    }

    cout << ans << endl;
}