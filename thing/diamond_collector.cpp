//
// Created by innav_z3e3dq9 on 6/15/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> sizes;
    for (int i = 0; i<n; i++) {
        int temp;
        cin >> temp;
        sizes.push_back(temp);
    }
    sort(sizes.begin(), sizes.end());
    int max1 = -1;
    int right = 1;
    bool more_break = false;
    for (int i = 0; i<n; i++) {
        while (sizes[right] - sizes[i] <= 2*k) {
            right++;
            if (right > n) {
                more_break = true;
                break;
            } else if (right == n) {
                break;
            }
        }
        if (more_break) {
            break;
        }
        right--;
        max1 = max(max1, right-i);
    }
}