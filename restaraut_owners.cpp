//
// Created by innav_z3e3dq9 on 6/3/2024.
//

#include <bits/stdc++.h>
using namespace std;

struct Time {
    int time, value;
};

bool comp(Time a, Time b) {
    return a.time<b.time;
}

int main() {
    int n;
    cin >> n;
    vector<Time> cust;
    for (int i = 0; i<n; i++) {
        int s, e;
        cin >> s >> e;
        cust.push_back({s, 1});
        cust.push_back({e, -1});
    }
    sort(cust.begin(), cust.end(), comp);
    int sim = 0;
    int ans = 0;
    for (int i = 0; i<n*2; i++) {
        sim += cust[i].value;
        ans = max(ans, sim);
    }
    cout << ans << endl;
    return 0;
}