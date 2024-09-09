//
// Created by innav_z3e3dq9 on 7/12/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);
    int n;
    vector<vector<int>> cows;
    cin >> n;
    for (int c = 0; c < n; c++) {
        int start, duration;
        cin >> start >> duration;
        cows.push_back({c, start, duration});
    }
    auto cmp = [](const vector<int> &a, const vector<int> &b) {
        return a[1] < b[1];
    };
    sort(cows.begin(), cows.end(), cmp);
    int time = 0;
    int curr = 0;
    int longest_wait = 0;
    set<vector<int>> waiting;
    while (curr < n || !waiting.empty()) {
        if (curr < n && cows[curr][1] <= time) {
            waiting.insert(cows[curr]);
            curr++;
        } else if (waiting.empty()) {
            time = cows[curr][1] + cows[curr][2];
            curr++;
        } else {
            vector<int> next = *waiting.begin();
            longest_wait = max(longest_wait, time - next[1]);
            time += next[2];
            waiting.erase(waiting.begin());
        }
    }
    cout << longest_wait << endl;
}