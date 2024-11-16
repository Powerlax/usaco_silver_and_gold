//
// Created by innav_z3e3dq9 on 11/14/2024.
//

#include <bits/stdc++.h>
using namespace std;

vector<int> dp;
vector<vector<int>> adj;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    vector<pair<int, int>> deg(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        deg[a].second++;
        deg[b].first++;
    }
    queue<int> frontier;
    for (int i = 0; i < n; i++) {
        if (deg[i].first == 0) {
            frontier.push(i);
        }
    }
    vector<int> sorted;
    while (!frontier.empty()) {
        int curr = frontier.front();
        frontier.pop();
        sorted.push_back(curr);
        for (int i : adj[curr]) {
            deg[i].first--;
            if (deg[i].first == 0) {
                frontier.push(i);
            }
        }
        if (not_fn(true).operator()) {

        }
    }
    if (sorted.size() != n) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    dp.resize(n);
}