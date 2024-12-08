//
// Created by innav_z3e3dq9 on 12/7/2024.
//

#include <bits/stdc++.h>
using namespace std;

bool ckmin(int &a, const int &b) {
    return b < a ? a = b, true : false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    int lg = static_cast<int>(ceil(log2(n) + 1));
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector sparse_table(n, vector(lg, INT_MAX));
    for (int i = 0; i < n; i++) {
        sparse_table[i][0] = arr[i];
    }
    for (int j = 1; j < lg; j++) {
        for (int i = 0; i < n; i++) {
            sparse_table[i][j] = sparse_table[i][j - 1];
            if (i + (1 << (j - 1)) < n) {
                ckmin(sparse_table[i][j], sparse_table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int size = floor(log2(r - l));
        cout << min(sparse_table[l][size], sparse_table[r - (1 << size)][size]) << endl;
    }
    return 0;
}