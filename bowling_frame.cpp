//
// Created by innav_z3e3dq9 on 12/17/2024.
//

#include <bits/stdc++.h>
using namespace std;

int last_true(int low, int high, function<bool(int)> f) {
    low--;
    while (low < high) {
        if (const int middle = low + (high - low + 1) / 2; f(middle)) {
            low = middle;
        } else {
            high = middle + 1;
        }
    }
    return low;
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    //cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int w, b;
        cin >> w >> b;
        cout << last_true(0, 100000, [&](int size) {
            if (w + b >= (size * (size + 1)) / 2) {
                return true;
            }
            int white_left = w;
            int black_left = b;
            size++;
            while (size--) {
                if (max(white_left, black_left) >= size) {
                    if (white_left > black_left) {
                        white_left -= size;
                    } else {
                        black_left -= size;
                    }
                } else {
                    return false;
                }
            }
            return true;
        }) << endl;
    }
    return 0;
}