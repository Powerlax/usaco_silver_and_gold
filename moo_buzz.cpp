//
// Created by innav_z3e3dq9 on 12/12/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen("moobuzz.in", "r", stdin);
    //freopen("moobuzz.out", "w", stdout);
    int n;
    cin >> n;
    vector<long long> portion;
    for (int i = 0; i < 15; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            continue;
        }
        portion.push_back(i);
    }
    const int offset = (n % static_cast<int>(portion.size())) - 1;
    const long long levels = 15 * (n / static_cast<int>(portion.size()));
    cout << portion[offset] + levels << endl;
    return 0;
}