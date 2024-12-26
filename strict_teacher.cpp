//
// Created by innav_z3e3dq9 on 12/23/2024.
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
        int n, m, q;
        cin >> n >> m >> q;
        set<int> teacher_pos;
        for (int i = 0; i < m; i++) {
            int pos;
            cin >> pos;
            teacher_pos.insert(pos);
        }
        while (q--) {
            int david_pos;
            cin >> david_pos;
            auto top = teacher_pos.upper_bound(david_pos);
            auto bottom = teacher_pos.end();
            if (top != teacher_pos.begin()) {
                bottom = --top;
                ++top;
            }
            if (top != teacher_pos.end() && bottom != teacher_pos.end()) {
                const int david_new_pos = (*top + *bottom) / 2;
                cout << min(*top - david_new_pos, david_new_pos - *bottom) << endl;
            } else if (top != teacher_pos.end()) {
                 cout << *top - 1 << endl;
            } else {
                cout << n - *bottom << endl;
            }
        }
    }
    return 0;
}