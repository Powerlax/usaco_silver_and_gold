//
// Created by innav_z3e3dq9 on 1/20/2025.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    set<int> s;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
        s.insert(a);
    }
    map<int, int> save;
    int prev = 0;
    int j = 1;
    for (int it : s) {
        prev += it * j;
        save[it] = prev;
        j++;
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        const int saveable = min(v[x], y);
        const auto start = save.upper_bound(saveable);
        int sum = 0;
        auto start_pos = s.begin();
        if (start != save.begin()) {
            sum = --start->second;
            start_pos = s.lower_bound(v[start->first]);
        }
        s.erase(v[x]);
        s.insert(y);
        int i = 1;
        for (; start_pos != s.end(); ++start_pos) {
            sum += *start_pos * i;
            i++;
        }
        cout << sum << endl;
    }
    return 0;
}