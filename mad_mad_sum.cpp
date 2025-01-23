//
// Created by innav_z3e3dq9 on 1/19/2025.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int sum = 0;
        while (true) {
            bool cont = false;
            for (int i = 0; i < n; i++) {
                sum += arr[i];
                if (arr[i] != 0) {
                    cont = true;
                }
            }
            if (!cont) {
                break;
            }
            unordered_set<int> duplicate, already_in;
            priority_queue<int> mad;
            mad.push(0);
            for (int i = 0; i < n; i++) {
                if (!already_in.count(arr[i])) {
                    if (duplicate.count(arr[i])) {
                        mad.push(arr[i]);
                        already_in.insert(arr[i]);
                    } else {
                        duplicate.insert(arr[i]);
                    }
                }
                arr[i] = mad.top();
            }
        }
        cout << sum << endl;
    }
    return 0;
}