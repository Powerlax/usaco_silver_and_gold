//
// Created by innav_z3e3dq9 on 12/26/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    long long max_l = LLONG_MAX;
    unordered_set<long long> indiv_days;
    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        if (a < max_l) {
            max_l = a;
        }
        indiv_days.insert(a);
    }
    max_l /= 4;
    if (indiv_days.size() < 4) {
        cout << (max_l*(max_l+1)/2) << endl;
        exit(0);
    }
    vector<long long> days(indiv_days.begin(), indiv_days.end());
    unordered_set<long long> diffs;
    for (int i = 0; i < 4; i++) {
        for (int j = i; j < 4; j++) {
            const long long diff = abs(days[i] - days[j]);
            for (long long k = 1; k < static_cast<long long>(sqrt(diff) + 1); k++) {
                if (diff % k == 0) {
                    diffs.insert(k);
                    diffs.insert(diff/k);
                }
            }
        }
    }
    long long ans = 0;
    for (const long long l : diffs) {
        if (l > max_l) {
            continue;
        }
        unordered_set<long long> mods;
        for (const long long day : days) {
            mods.insert(day % l);
            if (mods.size() > 3) {
                break;
            }
        }
        if (mods.size() <= 3) {
            ans += l;
        }
    }
    cout << ans << endl;
    return 0;
}