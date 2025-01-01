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
        while (true) {
            visited.assign(n, false);
            bool changed = false;
            for (int i = 0; i < n; i++) {
                if (!visited[i]) {
                    cycle.clear();
                    find_cycle(i);
                }
                if (cycle.size() > 2) {
                    const int pointer1 = permutation[cycle[cycle.size() - 1]];
                    const int pointer2 = cycle[cycle.size() - 2];
                    swap(permutation[pointer1], permutation[pointer2]);
                    changed = true;
                    ans++;
                }
            }
            if (!changed) {
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}