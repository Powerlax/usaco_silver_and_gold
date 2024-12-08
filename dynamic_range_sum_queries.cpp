//
// Created by innav_z3e3dq9 on 11/30/2024.
//

#include <bits/stdc++.h>
using namespace std;

class SumSegmentTree {
    int len;
    vector<long long> tree;

public:
    explicit SumSegmentTree(const int n) : len(n), tree(n*2) {}

    void set(int node, const long long value) {
        node += len;
        tree[node] = value;
        for (; node > 1; node /= 2) {
            tree[node / 2] = tree[node] + tree[node ^ 1];
        }
    }

    [[nodiscard]] long long query(int left, int right) const {
        long long ans = 0;
        for (left += len, right += len; left < right; left /= 2, right /= 2) {
            if (left % 2 == 1) {
                ans += tree[left++];
            }
            if (right % 2 == 1) {
                ans += tree[--right];
            }
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    SumSegmentTree tree(n);
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        tree.set(i, x);
    }
    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            tree.set(x-1, y);
        } else {
            cout << tree.query(x-1, y) << endl;
        }
    }
    auto &os = cin >> n >> q;
    return 0;
}