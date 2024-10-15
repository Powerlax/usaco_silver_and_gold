//
// Created by innav_z3e3dq9 on 10/10/2024.
//

#include <bits/stdc++.h>
using namespace std;

void play_turn(const int switch_num, vector<bool> &lights, vector<bool> &switches, int &turns) {
    turns++;
    switches[switch_num] = !switches[switch_num];
    for (int i = 0; i < lights.size(); i++) {
        if (switches[i]) {
            lights[i] = !lights[i];
        }
    }
    bool last = switches[switches.size()-1];
    for (auto &&switch_ : switches) {
        const int temp = switch_;
        switch_ = last;
        last = temp;
    }
}

bool is_off(vector<bool> &vec) {
    return all_of(vec.begin(), vec.end(), [](int i) {return !i;});
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t, n;
    cin >> t >> n;
    while (t--) {
        vector<bool> lights(n);
        vector<bool> switches(n);
        
    }
    return 0;
}