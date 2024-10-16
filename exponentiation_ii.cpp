//
// Created by innav_z3e3dq9 on 8/27/2024.
//

#include <bits/stdc++.h>
using namespace std;

int m = 1000000007;

int modexp(int a, int b, int subtracted) {
    int mod = m-subtracted;
    if (b == 0) {
        return 1%mod;
    }
    long long u = modexp(a,b/2, subtracted);
    u = (u*u)%mod;
    if (b%2 == 1) {
        u = (u*a)%mod;
    }
    return u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << modexp(a,modexp(b, c,1),0) << endl;
    }
    return 0;
}