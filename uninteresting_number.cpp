//
// Created by innav_z3e3dq9 on 12/16/2024.
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
        string n;
        cin >> n;
        int twos = 0;
        int threes = 0;
        int sum = 0;
        for (const char i : n) {
            sum += i - '0';
            if (i == '2') {
                twos++;
            } if (i == '3') {
                threes++;
            }
        }
        bool solved = false;
        for (int i = 0; i <= twos && i < 9; i++) {
            for (int j = 0; j <= threes && j < 9; j++) {
                if ((sum + (i * 2) + (j * 6)) % 9 == 0) {
                    cout << "YES" << endl;
                    solved = true;
                    break;
                }
            }
            if (solved) {
                break;
            }
        }
        if (!solved) {
            cout << "NO" << endl;
        }
    }
    return 0;
}