//
// Created by innav_z3e3dq9 on 7/22/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> elsie_first(n);
    vector<int> elsie_second(n);
    vector<int> bessie;
    for (int i = 0; i<2*n; i++) {
        bessie.push_back(i);
    }
    for (int i = 0; i<n/2; i++) {
        cin >> elsie_first[i];
        bessie.erase(find(bessie.begin(), bessie.end(), elsie_first[i]));
    }
    for (int i = 0; i<n/2; i++) {
        cin >> elsie_second[i];
        bessie.erase(find(bessie.begin(), bessie.end(), elsie_second[i]));
    }
    int won = 0;
    sort(elsie_first.begin(), elsie_first.end());
    auto e = --elsie_first.end();
    auto b = --bessie.end();
    for (int i = 0; i<elsie_first.size(); i++) {
        if (*b > *e) {
            won++;
        }
        if (i != 0) {
            --b;
            --e;
        }
    }
    sort(elsie_second.begin(), elsie_second.end());
    e = elsie_second.begin();
    b = bessie.begin();
    for (int i = 0; i<elsie_second.size(); i++) {
        if (*b < *e) {
            won++;
        }
        if (i != elsie_second.size()-1) {
            ++b;
            ++e;
        }
    }
    cout << won;
    return 0;
}