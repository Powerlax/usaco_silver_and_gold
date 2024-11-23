//
// Created by innav_z3e3dq9 on 11/19/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    vector adj(n, vector<int>(n));
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        adj[a][b] = c;
        adj[b][a] = c;
    }
    vector distances(n, vector<long long>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j]) {
                distances[i][j] = adj[i][j];
            } else if (i != j) {
                distances[i][j] = 1000000000000000000;
            }
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                distances[i][j] = min(distances[i][j], abs(distances[i][k]+distances[k][j]));
            }
        }
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << (distances[a-1][b-1] == INT_MAX ? -1 : distances[a-1][b-1]) << endl;
    }
    return 0;
}