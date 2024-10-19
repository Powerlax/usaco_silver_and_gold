//
// Created by innav_z3e3dq9 on 10/18/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);
    int n;
    cin >> n;
    map<int, int> delta;
    long long curr_sum = 0, curr_delta = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        curr_sum += abs(a-b);
        if (abs(a-b) <= abs(a)) {
            continue;
        }
        delta[b]+= 2;
        if (a < 0 && a < b || a >= 0 && a >= b) {
            delta[0]--; delta[2*b]--;
        }
        if (a < 0 && a >= b || a >= 0 && a < b) {
            delta[2*a]--; delta[2*b-2*a]--;
        }
    }
    long long px = 0, ans = curr_sum;
    for (auto [x, dx] : delta) {
        curr_sum += curr_delta  * (x-px);
        px = x;
        curr_delta += dx;
        ans = min(ans, curr_sum);
    }
    cout << ans << endl;
    return 0;
}