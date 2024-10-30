#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    s = "?" + s;
    vector<char> encoded_str(s.length());
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'C') {
            encoded_str[i] = 1;
        }
        if (s[i] == 'O') {
            encoded_str[i] = 2;
        }
        if (s[i] == 'W') {
            encoded_str[i] = 3;
        }
    }
    int q;
    cin >> q;
    string ans;
    while (q--) {
        int l, r;
        cin >> l >> r;
        unsigned char acc = 0;
        for (int j = l; j <= r; j++) {
            acc ^= encoded_str[j];
        }
        ans += acc == 1 ? 'Y' : 'N';
    }
    cout << ans << "\n";
}