//
// Created by innav_z3e3dq9 on 12/1/2024.
//

#include <bits/stdc++.h>
using namespace std;

int sum(const vector<long long> &segment_tree, int a, int b) {
    const int c = static_cast<int>(segment_tree.size()) / 2;
    a += c;
    b += c;
    int s = 0;
    while (a <= b) {
        if (a % 2) {
            s += static_cast<int>(segment_tree[a++]);
        }
        if (!(b % 2)) {
            s += static_cast<int>(segment_tree[b--]);
        }
        a /= 2;
        b /= 2;
    }
    return s;
}

void add(vector<long long> &segment_tree, int k, const long long x) {
    const int c = static_cast<int>(segment_tree.size()) / 2;
    k += c;
    segment_tree[k] += x;
    for (k /= 2; k >= 1; k /= 2) {
        segment_tree[k] = segment_tree[2 * k] + segment_tree[2 * k + 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("haircut.in", "r", stdin);
    freopen("haircut.out", "w", stdout);
    int n;
    cin >> n;
    int count = 0;
    while (1 << count <= n + 1) {
        count++;
    }
    count = 1 << count;
    vector<long long> segment_tree(2 * count);
    vector<long long> ans(n + 2);
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        ans[a + 1] += sum(segment_tree, a + 1, n + 1);
        add(segment_tree, a, 1);
    }
    long long total = 0;
    for (int i = 0; i < n; i++) {
        total += ans[i];
        cout << total << endl;
    }
    return 0;
}