//
// Created by innav_z3e3dq9 on 12/7/2024.
//

#include <bits/stdc++.h>
using namespace std;

int comp(const int i, const int j, const int k, const vector<vector<int>> &lcp, const string &orig) {
    if (lcp[i][j] >= k) {
        return 0;
    }
    if (i + lcp[i][j] == orig.length()) {
        return -1;
    }
    if (j + lcp[i][j] == orig.length()) {
        return 1;
    }
    return (orig[i + lcp[i][j]] < orig[j + lcp[i][j]]) ? -1 : (orig[i + lcp[i][j]] > orig[j + lcp[i][j]]) ? 1 : 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    string s;
    cin >> n >> s;
    vector longest_common_prefix(n + 1, vector<int>(n + 1));
    for (int i = n-1; i >= 0; i--){
        for (int j = n-1; j >= 0; j--) {
            if (s[i] == s[j]) {
                longest_common_prefix[i][j] = longest_common_prefix[i+1][j+1] + 1;
            }
        }
    }
    vector differences(n + 1, vector<int>(n + 1));
    for (int p = 0; p < n; p++) {
        vector<int> a(n + 1), b(n + 1);
        int left = p + 1;
        for (int l = n ; l >= 1; l--) {
            while (left < n && comp(p, left, l, longest_common_prefix, s) <= 0) {
                left++;
            }
            b[l] = min(l + left,n + 1);
        }
        int right = p - 1;
        for (int l = 1; l <= n; l++){
            while (right >= 0 && comp(p, right, l, longest_common_prefix, s) < 0) {
                right--;
            }
            a[l] = right+1;
        }
        for (int l = 1; l <= n; l++){
            if (l + p > n) {
                continue;
            }
            differences[l][min(b[l] - a[l] - 1, n)]++;
        }
    }
    vector<int> ans(n + 1);
    for (int l = 1; l <= n; l++){
        int index = 0;
        for (int k = n; k >= l; k--){
            index += differences[l][k];
            ans[index]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}