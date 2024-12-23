//
// Created by innav_z3e3dq9 on 12/1/2024.
//

#include <bits/stdc++.h>
using namespace std;

class DistinctValuesSegmentTree {
    int n;
    vector<unordered_set<int>> tree;

public:
    explicit DistinctValuesSegmentTree(const int len) : n(len), tree(len * 2) {}

    void set(int node, const int value) {
        node += n;
        tree[node].insert(value);
        for (; node > 1; node /= 1) {
            auto temp = tree[node];
            temp.merge(tree[node ^ 1]);
            tree[node / 2] = temp;
        }
    }

    [[nodiscard]] int query(int left, int right) {
        unordered_set<int> ans;
        for (left += n, right += n; left < right; left /= 2, right /= 2) {
            if (left & 1) {
                ans.merge(tree[left++]);
            }
            if (right & 1) {
                ans.merge(tree[--right]);
            }
        }
        return static_cast<int>(ans.size());
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    DistinctValuesSegmentTree tree(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tree.set(i, x);
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << tree.query(a, b) << endl;
    }
    return 0;
}