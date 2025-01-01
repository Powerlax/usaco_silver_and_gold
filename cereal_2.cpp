//
// Created by innav_z3e3dq9 on 12/29/2024.
//

#include <bits/stdc++.h>
using namespace std;

int ans;
vector<int> permutation;
vector<pair<int, int>> preferences;

void dfs(set<int> &cows, set<int> &cereals, vector<int> &curr, int cows_fed) {
    if (cows.empty()) {
        if (cows_fed > ans) {
            ans = cows_fed;
            permutation = curr;
        }
        return;
    }
    for (auto it = cows.begin(); it != cows.end(); ++it) {
        int i = *it;
        curr.push_back(i);
        cows.erase(it);
        if (cereals.count(preferences[i].first)) {
            cereals.erase(preferences[i].first);
            dfs(cows, cereals, curr, cows_fed - 1);
            cereals.insert(preferences[i].first);
        } else if (cereals.count(preferences[i].second)) {
            cereals.erase(preferences[i].second);
            dfs(cows, cereals, curr, cows_fed - 1);
            cereals.insert(preferences[*it].second);
        } else {
            dfs(cows, cereals, curr, cows_fed);
        }
        cows.insert(i);
        curr.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    preferences.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> preferences[i].first >> preferences[i].second;
    }
    permutation.resize(n);
    ans = -1;
    set<int> cereals;
    for (int i = 1; i < m; i++) {
        cereals.insert(i);
    }
    set<int> cows;
    for (int i = 0; i < n; i++) {
        cows.insert(i);
    }
    cout << n - ans << endl;
    for (int i = 0; i < n; i++) {
        cout << permutation[i] << endl;
    }
}