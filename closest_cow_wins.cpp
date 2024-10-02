//
// Created by innav_z3e3dq9 on 8/21/2024.
//

#include <bits/stdc++.h>
#define taste first
#define loc second
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k, m, n;
    cin >> k >> m >> n;
    vector<pair<int, int>> patches;
    for (int i = 0; i<k; i++) {
        int a, b;
        cin >> a >> b;
        patches.emplace_back(b, a);
    }
    sort(patches.begin(), patches.end(), greater<>());
    set<int> other;
    for (int i = 0; i<m; i++) {
        int temp;
        cin >> temp;
        other.insert(temp);
    }
    set<double> mine;
    for (int i = 0; i<n; i++) {
        auto ito = other.upper_bound(patches[i].loc);
        int ou = -1;
        int od = -1;
        if (ito != other.end()) {
            ou = *ito;
        }
        if (ito != other.begin()) {
            --ito;
            od = *ito;
        }
        auto itm = mine.upper_bound(patches[i].loc);
        double mu = -1;
        double md = -1;
        if (itm != mine.end()) {
            mu = *itm;
        }
        if (itm != mine.begin()) {
            --itm;
            md = *itm;
        }

    }
    return 0;
}
