//
// Created by innav_z3e3dq9 on 12/1/2024.
//

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> tree;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            ans += static_cast<long long>(i - tree.order_of_key(x));
            tree.insert(x);
        }
        cout << ans << endl;
        char s;
    }
}