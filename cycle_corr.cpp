//
// Created by innav_z3e3dq9 on 7/24/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    set<int> others;
    unordered_map<int, pair<int, int>> a;
    unordered_map<int, pair<int, int>> b;
    vector<int> aa(n);
    vector<int> bb(n);
    for (int i = 1; i<=n; i++) {
        others.insert(i);
    }
    for (int i = 0; i<k; i++) {
        cin >> aa[i];
        if (others.count(aa[i]) == 1) others.erase(aa[i]);
    }
    for (int i = 0; i<k; i++) {
        cin >> bb[i];
        if (others.count(bb[i]) == 1) others.erase(bb[i]);
    }

    for (int i = 0; i<k; i++) {
        int right;
        int left;
        if (i == 0) {
            left = aa[k-1];
            right = aa[i+1];
        } else if (i == k-1) {
            right = aa[0];
            left = aa[i-1];
        } else {
            right = aa[i+1];
            left = aa[i-1];
        }
        a.insert({aa[i], {left, right}});
    }

    for (int i = 0; i<k; i++) {
        int right;
        int left;
        if (i == 0) {
            left = bb[k-1];
            right = bb[i+1];
        } else if (i == k-1) {
            right = bb[0];
            left = bb[i-1];
        } else {
            right = bb[i+1];
            left = bb[i-1];
        }
        b.insert({bb[i], {left, right}});
    }

    for (int i = 0; i<k; i++) {
        if (b.count(aa[i]) == 1) {
            int lb = b[aa[i]].first;
            int rb = b[aa[i]].second;
            int la = a[aa[i]].first;
            int ra = a[aa[i]].second;
            if (lb == la || lb == ra || rb == la || rb == ra) {
                others.insert(aa[i]);
            }
        }
    }
    for (int i = 0; i<k; i++) {
        if (a.count(bb[i]) == 1) {
            int lb = b[bb[i]].first;
            int rb = b[bb[i]].second;
            int la = a[bb[i]].first;
            int ra = a[bb[i]].second;
            if (lb == la || lb == ra || rb == la || rb == ra) {
                others.insert(bb[i]);
            }
        }
    }
    cout << others.size() << endl;
    /*
    for (int i : others) {
        cout << i;
    }
    cout << endl;
    cout << a[3].first << a[3].second << endl;
    cout << b[3].first << b[3].second << endl;
     */
    return 0;
}