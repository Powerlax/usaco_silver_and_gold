//
// Created by innav_z3e3dq9 on 11/2/2024.
//

#include <bits/stdc++.h>
using namespace std;

struct FencePost {
    int x, y;
    bool visited;
    int depth;
};

int main() {
    freopen("lasers.in", "r", stdin);
    freopen("lasers.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    FencePost start{}, end{};
    cin >> n >> start.x >> start.y >> end.x >> end.y;
    vector<FencePost> fences(n+2);
    map<int, vector<int>> adj[2];
    for (int i = 0; i < n; i++) {
        cin >> fences[i].x >> fences[i].y;
        adj[0][fences[i].x].push_back(i);
        adj[1][fences[i].y].push_back(i);
    }
    adj[0][start.x].push_back(n);
    adj[1][start.y].push_back(n);
    adj[0][end.x].push_back(n+1);
    adj[1][end.y].push_back(n+1);
    start.visited = true;
    fences[n] = start;
    fences[n+1] = end;
    queue<FencePost> frontier;
    frontier.push(start);
    while (!frontier.empty()) {
        FencePost fence = frontier.front();
        frontier.pop();
        if (fence.x == end.x && fence.y == end.y) {
            cout << fence.depth-1 << endl;
            return 0;
        }
        for (int i = 0; i<2; i++) {
            for (const auto index : adj[i][i ? fence.y : fence.x]) {
                if (auto node = fences[index]; !node.visited) {
                    node.visited = true;
                    node.depth = fence.depth + 1;
                    frontier.push(node);
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}