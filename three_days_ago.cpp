//
// Created by innav_z3e3dq9 on 8/13/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int cur_state = 0;
    map<int, long long> states;
    states[cur_state]++;
    for (auto digit : S) {
        cur_state ^= 1 << (digit - '0');
        states[cur_state]++;
    }
    long long ans = 0;
    for (auto [unneeded, count] : states) {
        ans += count * (count - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}