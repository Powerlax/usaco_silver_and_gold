//
// Created by innav_z3e3dq9 on 1/20/2025.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string input;
    cin >> input;
    long long ans = 0;
    vector<long long> bessie_prefix_sum(7);
    int n = static_cast<int>(input.length());
    for (const char letter : input) {
        bessie_prefix_sum[0]++;
        for (int d = 5; d >= 0; d--) {
            if (letter == "bessie"[d]) {
                bessie_prefix_sum[d + 1] += bessie_prefix_sum[d];
                bessie_prefix_sum[d] = 0;
            }
        }
        ans += bessie_prefix_sum[6] * n;
        bessie_prefix_sum[0] += bessie_prefix_sum[6];
        bessie_prefix_sum[6] = 0;
        n--;
    }
    cout << ans << endl;
    return 0;
}