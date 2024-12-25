//
// Created by innav_z3e3dq9 on 11/28/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int ans = 0;
    int right = -1;
    set<int> window;
    for (int i = 0; i < n; i++) {
        while (right < n - 1 && !window.count(arr[right + 1])) {
            window.insert(arr[++right]);
        }
        ans = max(ans, right - i + 1);
        window.erase(arr[i]);
    }
    cout << ans << endl;
    return 0;
}