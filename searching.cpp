//
// Created by innav_z3e3dq9 on 8/14/2024.
//

#include <bits/stdc++.h>
using namespace std;

long long recur(long long a, long long b) {
    if (a == b) {
        return 0;
    } else if (a > b) {
        return 1 +  a % 2 + recur((a + (a % 2)) / 2, b);
    } else {
        return min(b - a, 1 + b % 2 + recur(a, b / 2));
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long a, b;
        cin >> a >> b;
        cout << recur(a, b) << endl;
    }
}