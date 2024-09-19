//
// Created by innav_z3e3dq9 on 7/24/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    map<int, int> cows;
    for (int i = 0; i<n; i++) {
        int w, a;
        cin >> w >> a;
        cows.insert({w, a});
    }
    int ans = 0;
    int start = true;
    int next = 0;
    while (!cows.empty() && m != 0) {
        if (start) {
            auto it = cows.lower_bound(0);
            next = (it -> first) + k;
            if (cows[it -> first] == 1) {
                cows.erase(it);
            } else {
                cows[it -> first]--;
            }
            start = false;
            ans++;
        }
        else {
            auto it = cows.lower_bound(next);
            if (it == cows.end()) {
                start = true;
                m--;
            } else {
                next = (it -> first) + k;
                if ((it -> second) == 1) {
                    cows.erase(it);
                } else {
                    cows[it -> first]--;
                }
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}