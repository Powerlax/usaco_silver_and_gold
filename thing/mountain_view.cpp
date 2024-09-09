//
// Created by innav_z3e3dq9 on 6/5/2024.
//

#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
using namespace std;

struct Mountain {
    int right, left;
};
bool comp(Mountain m1, Mountain m2) {return m1.left == m2.left ? m1.right > m2.right : m1.left < m2.left;}


int main() {
    freopen("mountains.in", "r", stdin);
    int n;
    cin >> n;
    vector<Mountain> mounts;
    for (int i = 0; i<n; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        mounts.push_back({t1+t2, t1-t2});
    }
    sort(mounts.begin(), mounts.end(), comp);
    int rightest = -1;
    int count = 0;
    for (int i = 0; i<n; i++) {
        if (mounts[i].right > rightest) {
            count++;
            rightest = mounts[i].right;
        }
    }
    freopen("mountains.out", "w", stdout);
    cout << count << endl;
    return 0;
}