//
// Created by innav_z3e3dq9 on 11/16/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    const string o = "[###OREO###]";
    const string re = " [--------] ";
    const string ampersand = "\n";
    while (t--) {
        string s;
        cin >> s;
        int i = 0;
        while (i < s.size()) {
            if (s[i] == 'O') {
                cout << o << endl;
            } else if (s[i] == 'R') {
                cout << re << endl;
                i++;
            } else if (s[i] == '&') {
                cout << ampersand;
            }
            i++;
        }
    }
    return 0;
}