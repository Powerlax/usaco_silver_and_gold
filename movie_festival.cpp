//
// Created by innav_z3e3dq9 on 7/17/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> movies;
    for (int i = 0; i<n; i++) {
        int s, e;
        cin >> s >> e;
        movies.emplace_back(e,s);
    }
    sort(movies.begin(), movies.end());
    int end = -1;
    int ans = 0;
    for (int i = 0; i<n; i++) {
        if (movies[i].second >= end)  {
            ans++;
            end = movies[i].first;
        }
    }
    cout << ans << endl;
    return 0;
}