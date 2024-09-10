//
// Created by innav_z3e3dq9 on 6/12/2024.
//

#include <bits/stdc++.h>
using namespace std;

struct Something {
    int index, item;
};

bool comp(Something s1, Something s2) {return s1.item < s2.item;}

int main() {
    int n, x;
    cin >> n >> x;
    vector<Something> nums;
    for (int i = 0; i<n; i++) {
        int temp;
        cin >> temp;
        nums.push_back({i+1, temp});
    }
    sort(nums.begin(), nums.end(), comp);
    int left = 0;
    int right = n-1;
    for (int i = 0; i<2*n; i++) {
        if (left == right){
            cout << "IMPOSSIBLE";
            return 0;
        }
        if (nums[left].item + nums[right].item > x) {
            right--;
        } else if (nums[left].item + nums[right].item < x) {
            left++;
        } else {
            break;
        }
    }
    int z, y;
    z = min(nums[left].index, nums[right].index);
    y = max(nums[left].index, nums[right].index);
    if (z == y){
        cout << "IMPOSSIBLE";
        return 0;
    }
    cout << z << " " << y << endl;
}