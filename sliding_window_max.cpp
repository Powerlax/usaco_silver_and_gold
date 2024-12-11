//
// Created by innav_z3e3dq9 on 11/26/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> ans;
    multiset<int> window;
    for (int i = 0; i < k; i++) {
        window.insert(nums[i]);
    }
    for (int i = k; i < nums.size(); i++) {
        ans.push_back(*window.rbegin());
        window.erase(window.find(nums[i-k]));
        window.insert(nums[i]);
    }
    ans.push_back(*window.rbegin());
    return 0;
}