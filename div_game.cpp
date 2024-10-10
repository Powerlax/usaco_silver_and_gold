//
// Created by innav_z3e3dq9 on 8/23/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int ans = 0;
    long long n;
    cin >> n;
    for (long long i = 2; i*i<=n; i++) {
        int exp = 0;
        while (n % i == 0) {
            exp++;
            n /= i;
        }
        for (int j = 1; exp-j>=0; j++) {
            exp -= j;
            ans++;
        }
    }
    if (n>1) {
        ans++;
    }
    cout << ans << endl;
    return 0;
}