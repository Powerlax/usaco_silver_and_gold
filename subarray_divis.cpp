//
// Created by innav_z3e3dq9 on 6/17/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i<n; i++) {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    vector<int> pre;
    unordered_map<int, int> occur;
    int count = 0;
    for (int i = 0; i<n; i++) {
        count += nums[i];
        pre.push_back(count);
        occur[pre[i]%n]++;
    }
    int ans = 0;
    for (int i = 1; i<n; i++) {
        if (auto search = occur.find(i); search != occur.end()) {
            ans += occur[i]-1;
        }
    }
    if (auto search = occur.find(0); search != occur.end()) {
        ans += occur[0];
    }
    cout << ans;
}