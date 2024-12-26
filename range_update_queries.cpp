//
// Created by innav_z3e3dq9 on 12/1/2024.
//

#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    int n;
    vector<long long> tree;

public:
    explicit SegmentTree(const int len) : n(len), tree(len * 2) {}

    void set(int i, const long long val) {
        tree[i += n] += val;
        for (i /= 2; i; i /= 2) {
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
        }
    }

    [[nodiscard]] long long query(int left, int right) const {
        long long ans = 0;
        for (left += n, right += n + 1; left < right; left /= 2, right /= 2) {
            if (left & 1) {
                ans += tree[left++];
            }
            if (right & 1) {
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
    SegmentTree segment_tree(n + 1);
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        segment_tree.set(i, arr[i] - arr[i - 1]);
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int a, b;
            long long val;
            cin >> a >> b >> val;
            segment_tree.set(a, val);
            segment_tree.set(b + 1, -val);
        } else {
            int k;
            cin >> k;
            cout << segment_tree.query(1, k) << endl;
        }
    }
    return 0;
}