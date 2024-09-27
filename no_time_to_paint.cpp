//
// Created by innav_z3e3dq9 on 9/21/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector min_last(26, -1);
    vector<int> prefix(n+1);
    for (int i = 1; i<=n; i++) {
        int curr = s[i-1] - 'A';
        for (int c = 0; c<26; c++) {
            min_last[c] = min(curr, min_last[c]);
        }
        prefix[i] = prefix[i-1];
        if (min_last[curr] < curr) {
            prefix[i]++;
        }
        min_last[curr] = curr;
    }
    min_last = vector(26, -1);
    vector<int> suffix(n+2);
    for (int i = n; i>=1; i--) {
        int curr = s[i-1] - 'A';
        for (int c = 0; c<26; c++) {
            min_last[c] = min(curr, min_last[c]);
        }
        suffix[i] = suffix[i+1];
        if (min_last[curr] < curr) {
            suffix[i]++;
        }
        min_last[curr] = curr;
    }
    for (int i = 0; i<q; i++) {
        int a, b;
        cin >> a >> b;
        cout << prefix[a-1] + suffix[b+1] << endl;
    }
    return 0;
}