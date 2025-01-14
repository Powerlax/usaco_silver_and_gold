//
// Created by innav_z3e3dq9 on 1/5/2025.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> heights(n);
    unordered_map<int, int> pos;
    for (int i = 0; i < n; i++) {
        int height;
        cin >> height;
        pos[height] = i;
    }
    set<int> higher;
    long long ans = 0;
    for (int i = n; i > 0; i--) {
        int position = pos[i];
        auto it = higher.upper_bound(position);
        if (it != higher.end()) {
            ans += *it - position + 1;
        }
        if (it != higher.begin()) {
            --it;
            ans += position - *it + 1;
        }
        higher.insert(position);
    }
    cout << ans << endl;
    return 0;
}