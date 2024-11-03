//
// Created by innav_z3e3dq9 on 11/3/2024.
//

#include <bits/stdc++.h>
using namespace std;

vector<long long> heights;

bool comp(int ind, int i1, int i2) {
    int d1 = abs(ind - i1), d2 = abs(ind - i2);
    long long h1 = heights[i1] - heights[ind], h2 = heights[i2] - heights[ind];
    return h2 * d1 >= h1 * d2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n;
    heights.resize(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> heights[i];
    }
    set<int> seeable[n+1];
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (seeable[i].empty()) {
                seeable[i].insert(j);
            } else {
                if (comp(i, *seeable[i].rbegin(), j)) {
                    seeable[i].insert(j);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += static_cast<int>(seeable[i].size());
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        heights[x] += y;
        for (int j = 1; j <= x - 1; j++) {
            auto it = seeable[j].lower_bound(x);
            bool add = false;
            if ((*it) == x) {
                add = true;
                ++it;
            } else {
                --it;
                if (comp(j, (*it), x)) {
                    seeable[j].insert(x);
                    ans++;
                    add = true;
                    ++it;
                    ++it;
                }
            }
            if (add) {
                while (it != seeable[j].end() && !comp(j, x, (*it))) {
                    it = seeable[j].erase(it);
                    ans--;
                }
            }
        }
        ans -= static_cast<int>(seeable[x].size());
        seeable[x].clear();
        for (int j = x + 1; j <= n; j++) {
            if (seeable[x].empty()) {
                seeable[x].insert(j);
                ans++;
            } else {
                if (comp(x, *seeable[x].rbegin(), j)) {
                    seeable[x].insert(j);
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}