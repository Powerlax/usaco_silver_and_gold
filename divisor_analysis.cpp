//
// Created by innav_z3e3dq9 on 8/29/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int, int>> primes(n);
    for (int i = 0; i<n; i++) {
        cin >> primes[i].first >> primes[i].second;
    }
    long long num = 1;
    for (int i = 0; i<n; i++) {
        num *= primes[i].second+1;
    }
    cout << num << " ";
    long long sum = 1;
    for (int i = 0; i<n; i++) {
        sum *= (static_cast<long long>(pow(primes[i].first, primes[i].second + 1))-1)/(primes[i].first-1);
    }
    cout << sum << " ";
    long long mult = 0;
    for (int i = 0; i<n; i++) {
        mult *= static_cast<long long>(pow(primes[i].first, primes[i].second));
    }
    cout << static_cast<long long>(pow(mult, num / 2)) << " ";
    return 0;
}