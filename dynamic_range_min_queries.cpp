//
// Created by innav_z3e3dq9 on 11/29/2024.
//

#include <bits/stdc++.h>
using namespace std;

class MinSegmentTree {
    int len;
    vector<int> tree;

public:
    explicit MinSegmentTree(const int len) : len(len), tree(len * 2, INT_MAX) {}

    void set(int node, const int val) {
        node += len;
        tree[node] = val;
        for (; node > 1; node /= 2) {
            tree[node / 2] = std::min(tree[node], tree[node ^ 1]);
        }
    }

    [[nodiscard]] int range_min(int left, int right) const {
        int ans = INT_MAX;
        for (left += len, right += len; left < right; left /= 2, right /= 2) {
            if (left % 2 == 1) {
                ans = min(ans, tree[left++]);
            }
            if (right % 2 == 1) {
                ans = min(ans, tree[--right]);
            }
        }
        return ans;
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    MinSegmentTree<int> tree(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tree.set(i, x);
    }
    while (q--) {
        int type, arg1, arg2;
        cin >> type >> arg1 >> arg2;
        if (type == 1) {
            tree.set(arg1 - 1, arg2);
        } else if (type == 2) {
            cout << tree.range_min(arg1 - 1, arg2) << endl;
        }
    }
    return 0;
}