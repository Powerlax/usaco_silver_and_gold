//
// Created by innav_z3e3dq9 on 11/21/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<long long, int>>> edge(n+1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].emplace_back(c, b);
    }
    int s = 1;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    vector<long long> dist(n+1, 0x3f);
    dist[0] = 0;
    pq.emplace(dist[s] = 0, s);
    vector<long long> num(n+1);
    num[s] = 1;
    vector<int> minf(n+1);
    vector<int> maxf(n+1);
    vector<bool> visited(n+1);
    while (!pq.empty()) {
        const int vert = pq.top().second;
        pq.pop();
        if (visited[vert]) {
            continue;
        }
        visited[vert] = true;
        for (auto [cost, next] : edge[vert]) {
            if (const long long alt = cost + dist[vert]; alt == dist[next]) {
                num[next] = (num[next] + num[vert]) % (static_cast<int>(1e9) + 7);
                minf[next] = min(minf[next], minf[vert] + 1);
                maxf[next] = max(maxf[next], maxf[vert] + 1);
            } else if (alt < dist[next]) {
                num[next] = num[vert];
                minf[next] = minf[vert] + 1;
                maxf[next] = maxf[vert] + 1;
                pq.emplace(dist[next] = alt, next);
            }
        }
    }
    cout << dist[n] << " " << num[n] << " " << minf[n] << " " << maxf[n];
    return 0;
}