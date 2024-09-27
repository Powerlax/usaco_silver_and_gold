//
// Created by innav_z3e3dq9 on 9/21/2024.
//

#include <bits/stdc++.h>
using namespace std;

vector<pair<bool, bool>> visited;
vector<pair<int, int>> adj;
int ans, n, k, not_in;

void traverse(int node, int move) {
    if (adj[move].first == node) {
        not_in = 0;
        if (visited[adj[move].second].first || visited[adj[move].second].second) {
            return;
        }
        visited[adj[move].second].second = true;
        ans++;
        traverse(adj[move].second, (move == k-1) ? 0 : move + 1);
    } else if (adj[move].second == node) {
        not_in = 0;
        if (visited[adj[move].first].first == true || visited[adj[move].first].second) {
            return;
        }
        visited[adj[move].first].first = true;
        ans++;
        traverse(adj[move].first, (move == k-1) ? 0 : move + 1);
    }
    else {
        not_in++;
        if (not_in == k) {
            return;
        }
        traverse(node, (move == k-1) ? 0 : move + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    adj = vector<pair<int, int>>(k);
    for (int i = 0; i < k; i++) {
        cin >> adj[i].first >> adj[i].second;
        adj[i].first--;
        adj[i].second--;
    }
    for (int i = 0; i < n; i++) {
        ans = 1, not_in = 0;
        visited = vector<pair<bool, bool>>(n);
        visited[i].second = true;
        traverse(i, 0);
        cout << ans << endl;
    }
    return 0;
}