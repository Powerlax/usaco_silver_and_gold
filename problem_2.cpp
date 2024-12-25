//
// Created by innav_z3e3dq9 on 12/14/2024.
//

#include <bits/stdc++.h>
using namespace std;

struct Tree {
    int pos, buffer, needed_for;
};

bool compare(Tree a, Tree b) {
    if (a.buffer == b.buffer) {
        return a.needed_for < b.needed_for;
    }
    return a.buffer > b.buffer;
}

int last_true(int low, int high, function<bool(int)> f) {
    low--;
    while (low < high) {
        if (const int middle = low + (high - low + 1) / 2; f(middle)) {
            low = middle;
        } else {
            high = middle - 1;
        }
    }
    return low;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<Tree> trees(n);
        for (int i = 0; i < n; i++) {
            cin >> trees[i].pos;
            trees[i].buffer = INT_MAX;
        }
        vector<tuple<int, int, int>> restrictions(k);
        for (int i = 0; i < k; i++) {
            int l, r, T;
            cin >> l >> r >> T;
            restrictions[i] = {l, r, T};
        }
        for (auto &[l, r, T] : restrictions) {
            vector<int> tree_in;
            int buffer_for_this = 0;
            for (int i = 0; i < n; i++) {
                if (trees[i].pos >= l && trees[i].pos <= r) {
                    tree_in.push_back(i);
                    buffer_for_this++;
                }
            }
            for (auto i : tree_in) {
                trees[i].buffer = min(trees[i].buffer, buffer_for_this-T);
                trees[i].needed_for++;
            }
        }
        sort(trees.begin(), trees.end(), compare);
        cout << last_true(0, n, [&](const int min_trees) {
            vector my_trees = trees;
            my_trees.erase(my_trees.begin(), my_trees.begin() + min_trees);
            for (auto &[l, r, T]: restrictions) {
                int trees_in = 0;
                for (int j = 0; j < my_trees.size(); j++) {
                    if (my_trees[j].pos >= l && my_trees[j].pos <= r) {
                        trees_in++;
                    }
                }
                if (trees_in < T) {
                    return false;
                }
            }
            return true;
        }) << endl;
    }
}