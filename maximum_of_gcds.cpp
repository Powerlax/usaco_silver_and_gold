//
// Created by innav_z3e3dq9 on 8/24/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        int highest = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            highest = max(highest, arr[i]);
        }
        int last_used = 0;
        for (int i = 0; i<n; i++) {
            if (last_used == 1) {
                cout << 1 << " ";
                continue;
            }
            if (i == 0) {
                cout << highest << " ";
                continue;
            }
            // TODO: everything else lol
        }
        cout << endl;
    }
    return 0;
}