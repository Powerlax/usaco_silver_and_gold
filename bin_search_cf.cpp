//
// Created by innav_z3e3dq9 on 7/30/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i<k; i++) {
        int temp;
        cin >> temp;
        cout << (binary_search(arr.begin(), arr.end(), temp) ? "YES" : "NO") << endl;
    }
}