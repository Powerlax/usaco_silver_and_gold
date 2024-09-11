//
// Created by innav_z3e3dq9 on 9/4/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector prefix_sum(n+1, vector<long long>(k+1, 0));
    for (int i = 0; i<n; i++) {
        prefix_sum[i][0] = 1;
    }
    for (int i = 1; i<=n; i++) {
        for (int j = 1; j<=k; j++) {
            prefix_sum[i][j] = prefix_sum[i-1][j] + prefix_sum[i-1][j-1];
        }
    }
    long long ans = 0;
    for (int i = 0; i<=k; i++) {
        vector<int> temp;
        int amount = 0;
        for (int j = 0; j<i; j++) {
            temp.push_back(j);
        }
        do {
            bool good = true;
            for (int j = 0; j<i; j++) {
                if (temp[j] == j) {
                    good = false;
                }
            }
            if (good) {
                amount++;
            }
        } while (next_permutation(temp.begin(), temp.end()));
        ans += prefix_sum[n][i] * amount;
    }
    cout << ans+1 << endl;
}