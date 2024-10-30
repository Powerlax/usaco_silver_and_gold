//
// Created by innav_z3e3dq9 on 8/9/2024.
//

#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj[5001];
bool visited[5001];

int bfs(int start, int k) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int count = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto &neighbor : adj[node]) {
            int next_node = neighbor.first;
            int relevance = neighbor.second;
            if (!visited[next_node] && relevance >= k) {
                visited[next_node] = true;
                q.push(next_node);
                count++;
            }
        }
    }
    return count;
}

int main() {
    ifstream fin("mootube.in");
    ofstream fout("mootube.out");
    int N, Q;
    fin >> N >> Q;
    for (int i = 0; i < N - 1; i++) {
        int p, q, r;
        fin >> p >> q >> r;
        adj[p].emplace_back(q, r);
        adj[q].emplace_back(p, r);
    }
    for (int i = 0; i < Q; i++) {
        int k, v;
        fin >> k >> v;
        memset(visited, false, sizeof(visited));
        int result = bfs(v, k);
        fout << result << endl;
    }
    fin.close();
    fout.close();
    return 0;
}