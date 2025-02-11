//
// Created by innav_z3e3dq9 on 2/8/2025.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> sizes(n);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> sizes[i];
        ans += sizes[i];
    }
    auto min_pos = ++min_element(sizes.begin(), sizes.end());
    rotate(sizes.begin(), min_pos, sizes.end());
    vector<int> stack;
    vector<long long> reduce(n + 5, 0);
    auto proc_stack = [&](const int pos){
        for (int i = 1; i < stack.size(); i++){
            const int delta = sizes[stack[i]] - sizes[stack[i - 1]];
            reduce[stack[i - 1] - pos] += delta;
        }
    };
    for (int i = n - 1; i >= 0; i--){
        while (stack.size() && sizes[stack.back()] >= sizes[i]) {
            stack.pop_back();
        }
        stack.push_back(i);
        proc_stack(i);
    }
    for (int i = 1; i <= n; i++){
        ans -= reduce[i];
        cout << ans << endl;
    }
}