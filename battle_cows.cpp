//
// Created by innav_z3e3dq9 on 12/25/2024.
//

#include <bits/stdc++.h>
using namespace std;

vector<int> ratings;
int n, k;

int simulate(const int pos) {
    vector<int> my_ratings = ratings;
    swap(my_ratings[k], my_ratings[pos]);
    int highest = 0;
    for (int i = 0; i < pos; i++) {
        highest = max(highest, my_ratings[i]);
    }
    if (highest > my_ratings[pos]) {
        return 0;
    }
    int ans = 0;
    if (pos != 0) {
        ans++;
    }
    for (int i = pos + 1; i < n; i++) {
        if (my_ratings[pos] > my_ratings[i]) {
            ans++;
        } else {
            break;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        k--;
        ratings.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> ratings[i];
        }
        bool already_solved = false;
        for (int i = 0; i < k; i++) {
            if (ratings[i] > ratings[k]) {
                if (i > 0) {
                    cout << max(simulate(i - 1), simulate(i)) << endl;
                } else {
                    cout << simulate(i) << endl;
                }
                already_solved = true;
                break;
            }
        }
        if (!already_solved) {
            cout << simulate(0) << endl;
        }
    }
    return 0;
}