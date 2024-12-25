//
// Created by innav_z3e3dq9 on 12/14/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        deque<int> cake_sizes(n);
        for (int i = 0; i < n; i++) {
            cin >> cake_sizes[i];
        }
        bool bessies_turn = true;
        int elsie_score = 0;
        for (int i = 0; i < n; i++) {
            if (bessies_turn) {
                if (cake_sizes.size() == 2) {
                    break;
                }
                cake_sizes[(cake_sizes.size() / 2) - 1] += cake_sizes[cake_sizes.size() / 2];
                cake_sizes.erase(cake_sizes.begin() + (static_cast<int>(cake_sizes.size()) / 2));
                bessies_turn = false;
            } else {
                int middle = (cake_sizes.size() / 2);
                if (cake_sizes[middle-1] < cake_sizes[middle+1]) {
                    elsie_score += cake_sizes[cake_sizes.size()-1];
                    cake_sizes.pop_back();
                } else {
                    elsie_score += cake_sizes[0];
                    cake_sizes.pop_front();
                }
                bessies_turn = true;
            }
        }
        cout << cake_sizes[0] + cake_sizes[1] << " " << elsie_score << endl;
    }
    return 0;
}
