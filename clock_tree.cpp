//
// Created by innav_z3e3dq9 on 8/11/2024.
//

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[2501];
int clocks[2501];
int N;

void dfs(int v, int p, vector<int>& clock) {
    for (int u : adj[v]) {
        if (u == p) continue;
        clock[u] = (clock[u] + 1) % 12;
        dfs(u, v, clock);
    }
}

bool can_synchronize(int start) {
    vector<int> clock(clocks, clocks + N + 1);
    dfs(start, -1, clock);
    for (int i = 1; i <= N; ++i) {
        if (clock[i] != 12) return false;
    }
    return true;
}

int main() {
    ifstream fin("clocktree.in");
    ofstream fout("clocktree.out");
    fin >> N;
    for (int i = 1; i <= N; ++i) {
        fin >> clocks[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        fin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int count = 0;
    for (int i = 1; i <= N; ++i) {
        if (can_synchronize(i)) {
            count++;
        }
    }
    fout << count << endl;
    fin.close();
    fout.close();
    return 0;
}