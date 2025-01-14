//
// Created by innav_z3e3dq9 on 12/13/2024.
//

#include <bits/stdc++.h>
using namespace std;

vector<int> folders;

bool comp(const int i, const int j) {
    return folders[i] > folders[j];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int m, n, k;
        cin >> m >> n >> k;
        folders.resize(n);
        vector<int> remaining(m);
        for (int i = 0; i < n; i++) {
            cin >> folders[i];
            folders[i]--;
            remaining[folders[i]]++;
        }
        int curr_folder = 0, l = 0, r = k - 1;
        vector<bool> ok(n);
        priority_queue<int, vector<int>, decltype(comp)*> pq{comp};
        for (int i = 0; i < k; i++) {
            pq.push(i);
        }
        while (r < n - 1 && curr_folder < m) {
            if (remaining[curr_folder] == 0) {
                curr_folder++;
            } else if (!pq.empty() && folders[pq.top()] < curr_folder + k) {
                const int curr = pq.top();
                pq.pop();
                if (curr >= l) {
                    ok[curr] = true;
                    remaining[folders[curr]]--;
                    r++;
                    pq.push(r);
                }
            } else {
                while(l < n && ok[l]) {
                    l++;
                }
                l++;
                r++;
                pq.push(r);
            }
        }
        bool impossible = false;
        while (curr_folder < m) {
            if (remaining[curr_folder] == 0) {
                curr_folder++;
            } else {
                if (pq.empty()) {
                    cout << "NO" << endl;
                    impossible = true;
                    break;
                }
                const int curr = pq.top();
                pq.pop();
                if (curr >= l && !ok[curr]) {
                    if (folders[curr] >= curr_folder + k) {
                        cout << "NO" << endl;
                        impossible = true;
                        break;
                    }
                    ok[curr] = true;
                    remaining[folders[curr]]--;
                    while(l > 0) {
                        l--;
                        if (!ok[l]) {
                            pq.push(l);
                            break;
                        }
                    }
                }
            }
        }
        if (!impossible) {
            cout << "YES" << endl;
        }
    }
    return 0;
}