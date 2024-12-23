//
// Created by innav_z3e3dq9 on 12/13/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a_cycle(n);
    vector<int> b_cycle(n);
    map<int, int> b_location;
    for (int i = 0; i < k; i++) {
        cin >> a_cycle[i];
    }
    for (int i = 0; i < k; i++) {
        cin >> b_cycle[i];
        b_location[b_cycle[i]] = i;
    }
    int shared_num_pos = -1;
    for (int i = 0; i < k; i++) {
        if (b_location.count(a_cycle[i])) {
            shared_num_pos = i;
        }
    }
    if (shared_num_pos == -1) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < k; i++) {
    }
    return 0;
}
