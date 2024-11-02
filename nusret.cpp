//
// Created by innav_z3e3dq9 on 6/23/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i<n; i++) {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    for (int i = 1; i<n; i++) {
        nums[i] = max(nums[i], nums[i-1]-m);
    }
    for (int i = n-2; i>=0; i--) {
        nums[i] = max(nums[i], nums[i+1]-m);
    }
    for (auto i : nums) {
        cout << i << " ";
    }
    return 0;
}