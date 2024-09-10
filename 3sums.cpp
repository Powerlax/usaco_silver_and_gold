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
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        nums.push_back({i+1, temp});
    }
    sort(nums.begin(), nums.end(), comp);
    for (int i = 0; i < n - 2; i++) {
        int left = i + 1, right = n - 1;
        while (left < right) {
            int sum = nums[i].item + nums[left].item + nums[right].item;
            if (sum < x) {
                left++;
            } else if (sum > x) {
                right--;
            } else {
                int a = min({nums[i].index, nums[left].index, nums[right].index});
                int b = max({nums[i].index, nums[left].index, nums[right].index});
                int c = nums[i].index + nums[left].index + nums[right].index - a - b;
                cout << a << " " << c << " " << b << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}