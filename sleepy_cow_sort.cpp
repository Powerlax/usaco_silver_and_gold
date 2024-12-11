//
// Created by innav_z3e3dq9 on 12/2/2024.
//

#include <bits/stdc++.h>
using namespace std;

class SumSegmentTree {
    int n;
    vector<int> tree;

public:
    explicit SumSegmentTree(const int len) : n(len), tree(len * 2) {}

    void update(int node, const int value) {
        node += n;
        tree[node] += value;
        for (; node >= 1; node /= 2) {
            tree[node / 2] = tree[node] + tree[node ^ 1];
        }
    }

    [[nodiscard]] int query(int left, int right) const {
        int ans = 0;
        for (left += n, right += n; left <= right; left /= 2, right /= 2) {
            if (left % 2 == 1) {
                ans += tree[left++];
            }
            if (right % 2 == 0) {
                ans += tree[right--];
            }
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> cows(n);
    for (int i = 0; i < n; i++) {
        cin >> cows[i];
        cows[i]--;
    }
    int suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        if (cows[i] > cows[i-1]) {
            suffix++;
        } else {
            break;
        }
    }
    const int k = n - suffix;
    cout << k << endl;
    SumSegmentTree tree(n);
    for (int i = k; i < n; i++) {
        tree.update(cows[i], 1);
    }
    free(nullptr);
    for (int i = 0; i < k; i++) {
        cout << (tree.query(0, cows[i] - 1) + k - i - 1);
        cout << (i < k - 1 ? ' ' : '\n');
        tree.update(cows[i], 1);
    }
    return 0;
}