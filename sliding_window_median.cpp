//
// Created by innav_z3e3dq9 on 11/28/2024.
//

#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> arr;
multiset<int> high;
multiset<int> low;

void insert(const int val) {
    if (const int a = *low.rbegin(); a < val) {
        high.insert(val);
        if (high.size() > k / 2) {
            low.insert(*high.begin());
            high.erase(high.find(*high.begin()));
        }
    } else {
        low.insert(val);
        if (low.size() > (k + 1) / 2) {
            high.insert(*low.rbegin());
            low.erase(low.find(*low.rbegin()));
        }
    }
}

void erase(const int val) {
    if (high.find(val) != high.end()) {
        high.erase(high.find(val));
    } else {
        low.erase(low.find(val));
    }
    if (low.empty()) {
        low.insert(*high.begin());
        high.erase(high.find(*high.begin()));
    }
}

int main() {
    cin >> n >> k;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    low.insert(arr[0]);
    for (int i = 1; i < k; i++) {
        insert(arr[i]);
    }

    cout << *low.rbegin() << " ";
    for (int i = k; i < n; i++) {
        if (k == 1) {
            insert(arr[i]);
            erase(arr[i - k]);
        } else {
            erase(arr[i - k]);
            insert(arr[i]);
        }
        cout << *low.rbegin() << " ";
    }
    cout << endl;
}