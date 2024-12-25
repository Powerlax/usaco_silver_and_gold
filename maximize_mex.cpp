//
// Created by innav_z3e3dq9 on 12/17/2024.
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
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        map<int, int> frequency;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            frequency[arr[i]]++;
        }
        int ans = 0;
        while (true) {
            if (frequency[ans] < 1) {
                break;
            }
            if (frequency[ans] > 1) {
                frequency[ans + x] += frequency[ans] - 1;
            }
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}