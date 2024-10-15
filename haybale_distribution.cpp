//
// Created by innav_z3e3dq9 on 10/13/2024.
//

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> barn_locs;
vector<long long> prefix{0};
vector<int> unique_locs;

long long calc_prefix(const int l, const int r) {
    return prefix[r+1] - prefix[l];
}

long long evaluate(const int y, const int a, const int b) {
    const int i = unique_locs[y];
    long long ans = b * (calc_prefix(i, n-1) - static_cast<long long>(n - i) * static_cast<long long>(barn_locs[i]));
    ans += a * (static_cast<long long>(i) * barn_locs[i] - calc_prefix(0, i-1));
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    barn_locs = vector<int>(n);
    for (int i = 0; i < n; i++) {
        cin >> barn_locs[i];
    }
    sort(barn_locs.begin(), barn_locs.end());
    for (int i = 0; i < n; i++) {
        prefix.push_back(barn_locs[i] + prefix.back());
    }
    for (int i = 1; i < n; i++) {
        if (barn_locs[i] > barn_locs[i-1]) {
            unique_locs.push_back(i);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        int low = 0, high = unique_locs.size() - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (evaluate(mid, a, b) < evaluate(mid+1, a, b)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        cout << evaluate(low, a, b) << endl;
    }
    return 0;
}