//
// Created by innav_z3e3dq9 on 12/31/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    int ans = 0;
    int eighteen = n, twentyone = n, twentyfive = n;
    while (twentyone > 1) {
        twentyone -= 2;
        eighteen--;
        ans++;
    }
    while (twentyfive > 1) {
        twentyfive -= 2;
        ans++;
    }
    if (twentyone == 1 && twentyfive == 1) {
        ans++;
    }
    if (eighteen % 3 == 0) {
        ans += eighteen / 3;
    } else {
        ans += (eighteen / 3) + 1;
    }
    cout << ans << endl;
    return 0;
}