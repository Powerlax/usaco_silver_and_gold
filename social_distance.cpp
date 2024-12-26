//
// Created by innav_z3e3dq9 on 7/31/2024.
//

#include <bits/stdc++.h>
using namespace std;

long long last_true(long long lo, long long hi, function<bool(long long)> f) {
    lo--;
    while (lo < hi) {
        long long mid = lo + (hi - lo + 1) / 2;
        //cout << f(mid) << mid << endl;
        if (f(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    return lo;
}

int main() {
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<pair<long long, long long>> grass;
    for (int i = 0; i<m; i++) {
        long long a, b;
        cin >> a >> b;
        grass.emplace_back(a,b);
    }
    sort(grass.begin(), grass.end());
    cout << last_true(1, grass[m-1].second-grass[0].first+1, [&](long long x) {
        int j = 0;
        long long curr = grass[j].first;
        for (int i = 1; i<n; i++) {
            while (curr + x > grass[j].second) {
                if (j == m-1) {
                    return false;
                } else {
                    j++;
                }
            }
            curr = max(curr + x, grass[j].first);
        }
        return true;
    }) << endl;
    return 0;
}