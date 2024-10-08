//
// Created by innav_z3e3dq9 on 8/22/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        map<int, int> prime_factors;
        for (int i = 2; i*i <= x; i++) {
            while (x % i == 0) {
                prime_factors[i]++;
                x /= i;
            }
        }
        if (x > 1) {
            prime_factors[x]++;
        }
        int ans = 1;
        for (auto i : prime_factors) {
            ans *= i.second+1;
        }
        cout << ans << endl;
    }
    return 0;
}