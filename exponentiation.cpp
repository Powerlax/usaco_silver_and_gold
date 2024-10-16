//
// Created by innav_z3e3dq9 on 8/27/2024.
//

#include <bits/stdc++.h>
using namespace std;

int m = 1000000007;

int modexp(int a, int b) {
    if (b == 0) {
        return 1%m;
    }
    long long u = modexp(a,b/2);
    u = (u*u)%m;
    if (b%2 == 1) {
        u = (u*a)%m;
    }
    return u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        cout << modexp(a % m, b) % m << endl;
    }
    return 0;
}