//
// Created by innav_z3e3dq9 on 7/22/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> movies;
    for (int i = 0; i<n; i++) {
        int a,b;
        cin >> a >> b;
        movies.emplace_back(b,a);
    }
    sort(movies.begin(), movies.end());
    multiset<int> times;
    for (int i = 0; i<k; i++) {
        times.insert(0);
    }
    int ans = 0;
    for (int i = 0; i<n; i++) {
        auto save = times.upper_bound(movies[i].second);
        if (save != begin(times)) {
            times.erase(--save);
            times.insert(movies[i].first);
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}