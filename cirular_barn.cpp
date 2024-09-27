//
// Created by innav_z3e3dq9 on 8/17/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    vector<bool> prime(5000005, true);
    vector<int> turns(5000005);
    vector<int> mod4 = {2, 1, 2, 3};
    turns[0] = 0;
    turns[1] = 1;
    for (int i = 2; i<5000005; i++) {
        if (prime[i]) {
            for (int j = i; j<5000005; j+=i) {
                prime[j] = false;
            }
            mod4[i%4] = i;
        }
        turns[i] = (i-mod4[i%4]) / 2 + 1;
    }
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i<n; i++) {
            cin >> arr[i];
        }
        int room_with_lowest = INT_MAX;
        int room = -1;
        for (int i = 0; i<n; i++) {
            if (turns[arr[i]]/2 < room_with_lowest/2) {
                room_with_lowest = turns[arr[i]];
                room = i;
            }
        }
        if (arr[room] % 4 == 0) {
            cout << "Farmer Nhoj" << endl;
        } else {
            cout << "Farmer John" << endl;
        }
    }
    return 0;
}