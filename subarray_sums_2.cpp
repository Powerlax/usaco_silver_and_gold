//
// Created by innav_z3e3dq9 on 6/16/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> nums;
    int sum = 0;
    vector<long long> pre;
    for (int i = 0; i<n; i++) {
        int temp = 0;
        cin >> temp;
        nums.push_back(temp);
        sum += nums[i];
        pre.push_back(sum);
    }
    int count = 0;
    unordered_map<long long, int> thingy;
    for (int i = 0; i<n; i++) {
        if (pre[i] == x) {
            count++;
        }
        if (auto search = thingy.find(pre[i]-x); search != thingy.end()) {
            count += thingy[pre[i]-x];
        }
        thingy[pre[i]]++;
    }
    cout << count;
    return 0;
}