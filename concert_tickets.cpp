//
// Created by innav_z3e3dq9 on 7/12/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    map<int, int> tickets;
    vector<int> cust(m);
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        tickets[temp]++;
    }
    for (int i = 0; i < m; i++) {
        cin >> cust[i];
    }
    for (int i = 0; i<m; i++) {
        auto it = tickets.upper_bound(cust[i]);
        if (it != tickets.begin()) {
            it--;
            if (tickets[it->first] == 1) {
                tickets.erase(it->first);
            } else {
                tickets[it->first]--;
            }
            cout << it->first << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}