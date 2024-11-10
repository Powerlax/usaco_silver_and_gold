//
// Created by innav_z3e3dq9 on 7/12/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x, n;
    cin >> x >> n;
    set<int> loc;
    loc.insert(0);
    loc.insert(x);
    multiset<int> gaps;
    gaps.insert(x);
    for (int i = 0; i<n; i++) {
        int curr;
        cin >> curr;
        auto it = loc.upper_bound(curr);
        int upper = *it;
        int lower = *(--it);
        int gap = upper-lower;
        gaps.erase(gaps.find(gap));
        gaps.insert(curr-lower);
        gaps.insert(upper-curr);
        loc.insert(curr);
        cout << *(--gaps.end()) << " ";
    }
    return 0;
}