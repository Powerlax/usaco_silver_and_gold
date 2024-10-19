//
// Created by innav_z3e3dq9 on 10/17/2024.
//

#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("threesum.in", "r", stdin);
    freopen("threesum.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    vector<int> val(n);
    for (int i = 0; i < n; i++) {
        cin >> val[i];
        val[i] += 1000000;
    }
    vector ways(n, vector<long long>(n));
    vector<int> frq(2000000);
    for (int i = n - 2; i >= 0; i--) {
        frq[val[i + 1]]++;
        for (int j = i + 2; j < n; j++) {
            int compliment = (3000000) - (val[i] + val[j]);
            if (compliment >= 0 && compliment < (2000000)) {
                ways[i][j] = frq[compliment];
            }
            frq[val[j]]++;
        }
        for (int j = i + 1; j < n; j++) {
            frq[val[j]]--;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            ways[i][j] += (ways[i + 1][j] + ways[i][j - 1] - ways[i + 1][j - 1]);
        }
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << ways[l - 1][r - 1] << endl;
    }
}