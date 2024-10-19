//
// Created by innav_z3e3dq9 on 10/18/2024.
//

#include <bits/stdc++.h>
using namespace std;

int n, b, ans = INT_MAX;
vector<vector<bool>> visited;
vector<int> snow;
vector<pair<int, int>> boots;

void dfs(int depth, int boot) {
    if (visited[depth][boot]) {
        return;
    }
    visited[depth][boot] = true;
    if (depth == n - 1) {
        ans = min(boot, ans);
        return;
    }
    for (int i = depth + 1; i <= depth + boots[boot].second && i < n; i++) {
        if (snow[i] <= boots[boot].first) {
            dfs(i, boot);
        }
    }
    for (int i = boot; i < b; i++) {
        if (snow[depth] <= boots[i].first) {
            dfs(depth, i);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);
    cin >> n >> b;
    snow.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> snow[i];
    }
    boots.resize(b);
    for (int i = 0; i < b; i++) {
        cin >> boots[i].first >> boots[i].second;
    }
    visited.resize(n, vector(b, false));
    dfs(0, 0);
    cout << ans << endl;
    return 0;
}