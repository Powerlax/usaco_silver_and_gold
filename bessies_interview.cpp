//
// Created by innav_z3e3dq9 on 12/7/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> times(n);
    for (int i = 0; i < n; i++) {
        cin >> times[i];
    }
    unordered_map<int, vector<int>> edges_into;
    priority_queue<int, vector<int>, greater<>> interviews;
    for (int i = 0; i < k; i++) {
        interviews.push(0);
    }
    for (const int time : times) {
        int start = interviews.top();
        interviews.pop();
        int end = start + time;
        edges_into[end].push_back(start);
        interviews.push(end);
    }
    vector<int> nodes;
    nodes.push_back(interviews.top());
    interviews.pop();
    unordered_set<int> visible;
    for (int i = 0; i < nodes.size(); i++) {
        int x = nodes[i];
        if (visible.find(x) != visible.end()) {
            continue;
        }
        visible.insert(x);
        if (edges_into.find(x) == edges_into.end()) {
            continue;
        }
        for (int next : edges_into[x]) {
            nodes.push_back(next);
        }
    }
    cout << nodes[0] << endl;
    string result;
    for (int i = 0; i < k; i++) {
        if (visible.find(times[i]) != visible.end()) {
            result += "1";
        } else {
            result += "0";
        }
    }
    cout << result << endl;
    return 0;
}