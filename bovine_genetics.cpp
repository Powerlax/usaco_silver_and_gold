//
// Created by innav_z3e3dq9 on 11/17/2024.
//

#include <bits/stdc++.h>
using namespace std;

vector options = {'G', 'A', 'T', 'C'};
vector<string> perms;

void generate_perms(const string &curr, const int depth) {
    if (depth == 0) {
        perms.push_back(curr);
        return;
    }
    for (const char option : options) {
        generate_perms(curr + option, depth - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string end;
    cin >> end;
    const int len = static_cast<int>(end.size());
    generate_perms("", len);
    int ans = 0;
    for (string possibility : perms) {
        vector<string> splits;
        char last = ' ';
        int last_pos = 0;
        for (int i = 0; i < len; i++) {
            if (possibility[i] == last) {
                splits.push_back(possibility.substr(last_pos, i-last_pos));
                last_pos = i;
            }
            last = possibility[i];
        }
        string asdf;
        for (string &s : splits) {
            reverse(s.begin(), s.end());
            asdf += s;
        }
        bool good = true;
        for (int i = 0; i < len; i++) {
            if (end[i] != '?' && end[i] != possibility[i]) {
                good = false;
                break;
            }
        }
        if (good) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}