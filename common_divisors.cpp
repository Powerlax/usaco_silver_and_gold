//
// Created by innav_z3e3dq9 on 8/24/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> div_count((1e6)+1);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        for (int j = 1; j*j <= a; j++) {
            if (a%j == 0) {
                div_count[j]++;
                if (j != a/j) {
                    div_count[a/j]++;
                }
            }
        }
    }
    for (int i = 1e6; i >= 1; i--) {
        if (div_count[i] >= 2) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}