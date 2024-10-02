//
// Created by innav_z3e3dq9 on 9/28/2024.
//

#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> solve(string &a, string &b, int ai, int bi) {
    int n = a.length();
    vector<pair<int, int>> soln;
    int first_diff = -1;
    for (int i = 1; i<n; i++) {
        if (a[i] != a[0]) {
            first_diff = i;
            break;
        }
    }
    if (first_diff == -1) {
        bool used_beaker = false;
        for (int i = n-1; i >= 0; i--) {
            if (i == 0 || b[i-1] != b[i]) {
                break;
            }
            if (b[i] == a[0]) {
                soln.emplace_back(bi, ai);
            } else {
                soln.emplace_back(bi, 3);
                used_beaker = true;
            }
        }
        if (used_beaker) {
            soln.emplace_back(3, bi);
        }
        return soln;
    }
    int beaker_col = 0;
    for (int i = n-1; i >= 0; i--) {
        if (a[i-1] != a[i]) {
            if (i == 0) {
                break;
            }
            if (a[0]-'0' == beaker_col && i == first_diff) {
                break;
            }
            if (b[n-1] == a[i]) {
                soln.emplace_back(ai, bi);
            } else {
                soln.emplace_back(ai, 3);
                beaker_col = a[i]-'0';
            }
        }
    }
    for (int i = n-1; i >= 0; i--) {
        if (i == 0 || b[i-1] != b[i]) {
            if (i == 0 && b[0] != a[0]) {
                break;
            }
            if ((beaker_col == 0 && b[i] != a[0]) || b[i]-'0' == beaker_col) {
                soln.emplace_back(bi, 3);
            } else {
                soln.emplace_back(bi, ai);
            }
        }
    }
    if (a[0]-'0' == beaker_col) {
        soln.emplace_back(ai, bi);
        soln.emplace_back(3, ai);
        return soln;
    }
    soln.emplace_back(3, bi);
    return soln;
}

void print_soln(vector<pair<int, int>> &soln, int p) {
    cout << soln.size() << endl;
    if (p >= 2) {
        for (auto &[a, b] : soln) {
            cout << a << " " << b << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int z = 0; z < t; z++) {
        int n, p;
        cin >> n >> p;
        string a, b;
        cin >> a >> b;
        auto s1 = solve(a, b, 1, 2);
        auto s2 = solve(b, a, 2, 1);
        if (s1.size() < s2.size()) {
            print_soln(s1, p);
        } else {
            print_soln(s2, p);
        }
    }
    return 0;
}