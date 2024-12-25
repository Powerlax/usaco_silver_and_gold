//
// Created by innav_z3e3dq9 on 12/24/2024.
//

#include <bits/stdc++.h>
using namespace std;

struct Constraint {
    int until, affected;
};

bool comp(const Constraint &a, const Constraint &b) {
    return a.affected < b.affected;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, q, c;
        cin >> n >> q >> c;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            cin >> ans[i];
        }
        vector<Constraint> rules(q);
        for (int i = 0; i < q; i++) {
            cin >> rules[i].until >> rules[i].affected;
            rules[i].affected--;
        }
        sort(rules.begin(), rules.end(), comp);
        queue<Constraint> order;
        for (int i = 0; i < q; i++) {
            order.push(rules[i]);
        }
        vector<int> maxes(n+1);
        for (int i = 0; i < n; i++) {
            if (order.front().affected == i) {
                if (ans[i] == 0) {
                    cout << -1;
                }
            }
        }
        bool failed = false;
        for (int i = 0; i < n; i++) {
            if (ans[i] > c) {
                cout << -1 << endl;
                failed = true;
                break;
            }
        }
        if (!failed) {
            for (int i = 0; i < n; i++) {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}