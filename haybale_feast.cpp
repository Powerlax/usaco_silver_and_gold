//
// Created by innav_z3e3dq9 on 11/23/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("hayfeast.in", "r", stdin);
    freopen("hayfeast.out", "w", stdout);
    int n;
    long long m;
    cin >> n >> m;
    vector<pair<int, int>> haybales(n);
    for (int i = 0; i < n; i++) {
        cin >> haybales[i].first >> haybales[i].second;
    }
    int ans = INT_MAX;
    long long score = 0;
    multiset<int> spices;
    int right = 0;
    for (int left = 0; right < n; left++) {
        while (right < n && score < m) {
            score += haybales[right].first;
            spices.insert(haybales[right].second);
            right++;
        }
        if (score >= m) {
            ans = min(ans, *spices.rbegin());
        }
        score -= haybales[left].first;
        spices.erase(spices.find(haybales[left].second));
    }
    cout << ans << endl;
    return 0;
}