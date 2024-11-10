//
// Created by innav_z3e3dq9 on 11/9/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    vector<int> last_appeared(51), parent(51);
    while (t--) {
        int n, m;
        bool valid = true;
        vector<int> global_order;
        cin >> n >> m;
        for (int i = 0; i <= n; i++) {
            last_appeared[i] = -1;
            parent[i] = -1;
        }
        while (m--) {
            int k;
            cin >> k;
            stack<int> lines;
            vector<int> curr_order;
            int curr = 0;
            while (k--) {
                int c;
                cin >> c;
                if (!valid) {
                    continue;
                }
                if (last_appeared[c] == m && lines.top() == c) {
                    lines.pop();
                    curr = parent[curr];
                } else {
                    if ((~last_appeared[c] && last_appeared[c] != m + 1) || last_appeared[c] == m || (~last_appeared[c] && parent[c] != curr)) {
                        valid = false;
                        continue;
                    }
                    curr_order.push_back(c);
                    parent[c] = curr;
                    last_appeared[c] = m;
                    lines.push(c);
                    curr = c;
                }
            }
            if (!valid) {
                continue;
            }
            int index = 0;
            for (int i : curr_order) {
                while (index != global_order.size() && !count(curr_order.begin(), curr_order.end(), global_order[index])) {
                    index++;
                }
                if (!count(global_order.begin(), global_order.end(), i))
                    global_order.insert(global_order.begin() + index, i);
                else if (index == global_order.size() || global_order[index] != i) {
                    valid = false;
                    break;
                }
                index++;
            }
        }
        cout << (valid ? "YES" : "NO") << endl;
    }
    return 0;
}