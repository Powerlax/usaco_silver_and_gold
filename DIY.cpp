//
// Created by innav_z3e3dq9 on 1/1/2025.
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
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        unordered_map<int, int> frequency;
        for (int i = 0; i < n; i++) {
            frequency[nums[i]]++;
        }
        multiset<int> viable;
        for (auto it = frequency.begin(); it != frequency.end(); ++it) {
            int count = it->second;
            while (count >= 2) {
                viable.insert(it->first);
                count -= 2;
            }
        }
        if (viable.size() < 4) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            const int first = *viable.begin();
            const int second = *(++viable.begin());
            const int third = *(--(--viable.end()));
            const int fourth = *(--viable.end());
            cout << first << " " << second << " ";
            cout << first << " " << fourth << " ";
            cout << third << " " << second << " ";
            cout << third << " " << fourth << endl;
        }
    }
    return 0;
}