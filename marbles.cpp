//
// Created by innav_z3e3dq9 on 9/1/2024.
//

#include <bits/stdc++.h>
using namespace std;

long long bin_coff(int n, int k) {
    if (k > n - k) {
        k = n-k;
    }
    long long ans = 1;
    for (int i = 0; i < k; i++) {
        ans = ans * (n - i) / (i + 1);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        cout << bin_coff(n-1, k-1) << endl;
    }
    return 0;
}