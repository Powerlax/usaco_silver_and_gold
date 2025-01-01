//
// Created by innav_z3e3dq9 on 12/30/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (s[0] == 's') {
            s[0] = '.';
        }
        if (s[n-1] == 'p') {
            s[n-1] = '.';
        }
        queue<char> to_be_processed;
        for (int i = 0; i < n; i++) {
            if (s[i] != '.') {
                to_be_processed.push(s[i]);
            }
        }
        if (to_be_processed.size() > 1) {
            char last = to_be_processed.front();
            to_be_processed.pop();
            bool solvable = true;
            while (!to_be_processed.empty()) {
                if (to_be_processed.front() != last) {
                    solvable = false;
                    break;
                }
                last = to_be_processed.front();
                to_be_processed.pop();
            }
            if (solvable) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}