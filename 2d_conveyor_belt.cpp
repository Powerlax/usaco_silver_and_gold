//
// Created by innav_z3e3dq9 on 1/21/2025.
//

#include <bits/stdc++.h>
using namespace std;

constexpr int MAX = 1005;
constexpr int x_movements[] = {0, 0, -1, 1};
constexpr int y_movements[] = {-1, 1, 0, 0};
constexpr char directions[] = {'L', 'R', 'U', 'D'};

int n, q, curGood, good[MAX][MAX], dir[MAX][MAX];

bool isGood(const int i, const int j) {
    if (!(i >= 1 && i <= n && j >= 1 && j <= n)) {
        return false;
    }
    for (int d = 0; d < 4; d++) {
        if (dir[i][j] != -1 and d != dir[i][j])
            continue;
        const int ni = i + x_movements[d];
        const int nj = j + y_movements[d];
        if (!(ni >= 1 && ni <= n && nj >= 1 && nj <= n) || good[ni][nj]) {
            return true;
        }
    }
    return false;
}
void dfs(const int i, const int j) {
    if (!isGood(i, j) or good[i][j]) {
        return;
    }
    good[i][j] = true;
    curGood++;
    for (int d = 0; d < 4; d++) {
        dfs(i + x_movements[d], j + y_movements[d]);
    }
}

int main(){
    ios_base::sync_with_stdio(true);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dir[i][j] = -1;
        }
    }
    vector<tuple<int, int, char>> upds(q);
    for (auto &[r, c, t] : upds){
        cin >> r >> c >> t;
        dir[r][c] = find(directions, directions + 4, t) - directions;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                good[i][j] = 0;
            }
        }
        curGood = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dfs(i, j);
            }
        }
        cout << n * n - curGood << endl;
    }
}