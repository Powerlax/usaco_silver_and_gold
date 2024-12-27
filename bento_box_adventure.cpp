//
// Created by innav_z3e3dq9 on 12/26/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    unordered_set<int> already_visited;
    for (int i = 0; i < 4; i++) {
        int a;
        cin >> a;
        already_visited.insert(a);
    }
    for (int i = 1; i <= 5; i++) {
        if (already_visited.find(i) == already_visited.end()) {
            cout << i << endl;
            return 0;
        }
    }
}