//
// Created by innav_z3e3dq9 on 10/3/2024.
//

#include <bits/stdc++.h>
using namespace std;

void fill(vector<pair<int, int>> &path, const string &s) {
    for (int i = 1; i < path.size(); i++) {
        if (s[i-1] == 'N') {
            path[i].second = path[i-1].second + 1;
        } else if (s[i-1] == 'S') {
            path[i].second = path[i-1].second - 1;
        } else if (s[i-1] == 'E') {
            path[i].first = path[i-1].first + 1;
        } else {
            path[i].first = path[i-1].first - 1;
        }
    }
}

int dist(const pair<int, int> &a, const pair<int, int> &b) {
    return static_cast<int>(pow(a.second - b.second, 2)) + static_cast<int>(pow(a.first - b.first, 2)));
}

int main() {
    freopen("radio.in", "r", stdin);
    freopen("radio.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int fx, fy, bx, by;
    cin >> fx >> fy;
    cin >> bx >> by;
    vector<pair<int, int>> farm_pos(n+1), bessie_pos(m+1);
    farm_pos[0] = make_pair(fx, fx);
    bessie_pos[0] = make_pair(bx, by);
    string j, b;
    cin >> b >> j;
    fill(farm_pos, j);
    fill(bessie_pos, b);
    vector dp(n+1, vector(m+1, INT_MAX));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]+dist(farm_pos[i+1], farm_pos[i]));
        }
    }
    return 0;
}