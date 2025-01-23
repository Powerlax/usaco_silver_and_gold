//
// Created by innav_z3e3dq9 on 1/10/2025.
//

#include <bits/stdc++.h>
using namespace std;

int cost(const string &s) {
    if (static_cast<int>(s.length()) < 1) {
        return 0;
    }
    unordered_map<char, int> even;
    unordered_map<char, int> odd;
    for (int i = 0; i < s.length(); i++) {
        if (i % 2 == 0) {
            even[s[i]]++;
        } else {
            odd[s[i]]++;
        }
    }
    int top_even = -1, top_odd = -1;
    for (auto &[first, snd] : even) {
        top_even = max(top_even, snd);
    }
    for (auto &[fst, snd] : odd) {
        top_odd = max(top_odd, snd);
    }
    return static_cast<int>(s.length() - (top_even + top_odd));
}

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
        if (n % 2 == 0) {
            cout << cost(s) << endl;
        } else {
            int ans = INT_MAX;
            for (int i = 0; i < n; i++) {
                ans = min(ans, cost(s.substr(0, i)+s.substr(i + 1, n-i-1)));
            }
            cout << ans + 1  << endl;
        }
    }
    return 0;
}