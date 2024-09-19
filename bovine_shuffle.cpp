//
// Created by innav_z3e3dq9 on 8/12/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    long long n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> cows_after_shuffle(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        cows_after_shuffle[a[i]]++;
    }
    long long ans = n;
    queue<long long> no_cows;
    for (int i = 0; i < n; i++) {
        if (cows_after_shuffle[i] == 0) {
            no_cows.push(i);
            ans--;
        }
    }
    while (!no_cows.empty()) {
        long long curr = no_cows.front();
        no_cows.pop();
        if (--cows_after_shuffle[a[curr]] == 0) {
            no_cows.push(a[curr]);
            ans--;
        }
    }
    cout << ans << endl;
}