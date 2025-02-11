//
// Created by innav_z3e3dq9 on 1/23/2025.
//

#include <bits/stdc++.h>
using namespace std;


int last_true(int lo, int hi, function<bool(int)> f) {
    lo--;
    while (lo < hi) {
        if (const int mid = lo + (hi - lo + 1) / 2; f(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    return lo;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n = 0;
        cin >> n;
        multiset<int> apps;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            apps.insert(a);
        }
        multiset<int> mains;
        for (int i = 0; i < n; i++) {
            int b;
            cin >> b;
            mains.insert(b);
        }
        cout << last_true(0, 1000000001, [&](const int ans) {
            multiset<int> my_apps = apps;
            multiset<int> my_mains = mains;
            for (int i = 0; i < n; i++) {
                auto it = my_mains.lower_bound(*my_apps.begin() + ans);
                if (it == my_mains.end()) {
                    return false;
                }
                my_mains.erase(it);
                my_apps.erase(my_apps.begin());
            }
            return true;
        }) << endl;
    }
    return 0;
}