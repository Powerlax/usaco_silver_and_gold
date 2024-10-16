//
// Created by innav_z3e3dq9 on 8/14/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int c, n;
    cin >> c >> n;
    vector<int> teams(n);
    vector<int> edits(1 << c, INT32_MAX);
    for (int i = 0; i < n; i++) {
        string breeds;
        cin >> breeds;
        for (int j = 0; j < c; j++) {
            if (breeds[j] == 'G') { teams[i] += 1 << (c - j - 1); }
        }
        edits[teams[i]] = 0;
    }
    for (int edit = 0; edit < c; edit++) {
        for (int mask = 0; mask < (1 << c); mask++) {
            if (edits[mask] != INT32_MAX) {
                edits[mask ^ (1 << edit)] =
                        min(edits[mask ^ (1 << edit)], edits[mask] + 1);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << c - edits[teams[i] ^ ((1 << c) - 1)] << endl;
    }
}