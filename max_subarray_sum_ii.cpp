//
// Created by innav_z3e3dq9 on 11/26/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, a, b;
    cin >> n >> a >> b;
    vector<long long> prefix_sum(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        prefix_sum[i] = x + prefix_sum[i - 1];
    }
    long long ans = LLONG_MIN;
    multiset<long long> window;
    for (int i = a; i <= n; i++) {
        if (i > b) {
            window.erase(window.find(prefix_sum[i - b - 1]));
        }
        window.insert(prefix_sum[i - a]);
        ans = max(ans, prefix_sum[i] - *window.begin());
    }
    cout << ans << endl;
}