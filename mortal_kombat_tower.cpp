//
// Created by innav_z3e3dq9 on 9/10/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<bool> difficulty;
        for (int i = 0; i<n; i++) {
            int a;
            cin >> a;
            difficulty.push_back(a);
        }
        bool friends_turn = true;
        int actions_made = 0;
        int ans = 0;
        for (int i = 0; i<n; i++) {
            if (friends_turn) {
                if (!difficulty[i]) {
                    actions_made++;
                } else {
                    if (actions_made == 0) {
                        ans++;
                        actions_made++;
                    } else {
                        friends_turn = !friends_turn;
                        actions_made = 1;
                        continue;
                    }
                }
            } else {
                if (difficulty[i]) {
                    actions_made++;
                } else {
                    friends_turn = !friends_turn;
                    actions_made = 1;
                }
            }
            if (actions_made == 2) {
                friends_turn = !friends_turn;
                actions_made = 0;
            }
        }
        cout << ans << endl;
    }
    return 0;
}