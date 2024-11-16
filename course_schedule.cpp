//
// Created by innav_z3e3dq9 on 11/12/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("course.in", "r", stdin);
    freopen("course.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> degrees(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        degrees[a].second++;
        degrees[b].first++;
    }
    queue<int> frontier;
    for (int i = 0; i < n; i++) {
        if (degrees[i].first == 0) {
            frontier.push(i);
        }
    }
    vector<int> ans;
    while (!frontier.empty()) {
        int node = frontier.front();
        frontier.pop();
        ans.push_back(node);
        for (int i : adj[node]) {
            degrees[i].first--;
            if (degrees[i].first == 0) {
                frontier.push(i);
            }
        }
    }
    if (static_cast<int>(ans.size()) == n) {
        for (int i = 0; i < n; i++) {
            cout << ans[i]+1 << " ";
        }
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}