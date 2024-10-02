//
// Created by innav_z3e3dq9 on 10/1/2024.
//

#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

long long dist(pair<int, int> a, pair<int, int> b) {
    int i = (a.x - b.x);
    int j = (a.y - b.y);
    return (i * i) + (j * j);
}

int main() {
    freopen("checklist.in", "r", stdin);
    freopen("checklist.out", "w", stdout);
    int h, g;
    cin >> h >> g;
    vector<pair<int, int>> hs(h), gs(g);
    for (int i = 0; i < h; i++) {
        cin >> hs[i].x >> hs[i].y;
    }
    for (int i = 0; i < g; i++) {
        cin >> gs[i].x >> gs[i].y;
    }
    constexpr long long max_distance_traversable = 1e18;
    vector min_dist(h + 1, vector(g + 1, vector(2, max_distance_traversable)));
    min_dist[1][0][0] = 0;
    for (int i = 0; i <= h; i++) {
        for (int j = 0; j <= g; j++) {
            if (i > 1) {
                min_dist[i][j][0] = min(min_dist[i][j][0], min_dist[i - 1][j][0] + dist(hs[i - 2], hs[i - 1]));
            }
            if (j > 1) {
                min_dist[i][j][1] = min(min_dist[i][j][1], min_dist[i][j - 1][1] + dist(gs[j - 2], gs[j - 1]));
            }
            if (i > 0 && j > 0) {
                min_dist[i][j][0] = min(min_dist[i][j][0], min_dist[i - 1][j][1] + dist(hs[i - 1], gs[j - 1]));
                min_dist[i][j][1] = min(min_dist[i][j][1], min_dist[i][j - 1][0] + dist(hs[i - 1], gs[j - 1]));
            }
        }
    }

    cout << min_dist[h][g][0] << endl;
}