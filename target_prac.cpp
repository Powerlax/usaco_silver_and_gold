//
// Created by innav_z3e3dq9 on 7/24/2024.
//

#include <bits/stdc++.h>
using namespace std;

struct Action {
    bool fire;
    int movement;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, c;
    cin >> t >> c;
    vector<Action> actions;
    set<int> targets;
    for (int i = 0; i<t; i++) {
        int temp;
        cin >> temp;
        targets.insert(temp);
    }
    int movement = 0;
    bool move = false;
    string commands;
    cin >> commands;
    for (int i = 0; i<c; i++) {
        if (commands[i] == 'F') {
            if (move) {
                actions.push_back({false, movement});
                actions.push_back({true, 0});
                move = false;
                movement = 0;
            } else {
                actions.push_back({true, 0});
            }
        } else {
            move = true;
            if (commands[i] == 'L') {
                movement--;
            } else {
                movement++;
            }
        }
    }
    if (move) {
        actions.push_back({false, movement});
    }
    int ans = -1;
    for (int i = 0; i<actions.size(); i++) {
        if (actions[i].fire) {
            actions[i] = {false, 1};
            int changed = 0;
            int pos = 0;
            for (int j = 0; j<actions.size(); j++) {
                if (actions[j].fire && targets.count(pos)) {
                    changed++;
                } else {
                    pos += actions[j].movement;
                }
            }
            ans = max(ans, changed);

            actions[i] = {false, -1};
            changed = 0;
            pos = 0;
            for (int j = 0; j<actions.size(); j++) {
                if (actions[j].fire && targets.count(pos)) {
                    changed++;
                } else {
                    pos += actions[j].movement;
                }
            }
            ans = max(ans, changed);        }
    }
    return 0;
}