//
// Created by innav_z3e3dq9 on 1/1/2025.
//

#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<int> permutation;
vector<int> cycle;

void find_cycle(const int curr_node) {
    if (visited[curr_node]) {
        return;
    }
    cycle.push_back(curr_node);
    if (permutation[curr_node] == curr_node) {
        return;
    }
    visited[curr_node] = true;
    find_cycle(permutation[curr_node]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        permutation.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> permutation[i];
            permutation[i]--;
        }
        int ans = 0;
            visited.assign(n, false);
            for (int i = 0; i < n; i++) {
                if (!visited[i]) {
                    cycle.clear();
                    find_cycle(i);
                    if (cycle.size() > 2) {
                        ans += (cycle.size() - 1) / 2;
                    }
                }
            }
        cout << ans << endl;
    }
    return 0;
}