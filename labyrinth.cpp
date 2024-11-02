//
// Created by innav_z3e3dq9 on 10/31/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector board(n, vector<char>(m));
    pair<int, int> startPos, endPos;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'A') {
                startPos = make_pair(i, j);
            } else if (board[i][j] == 'B') {
                endPos = make_pair(i, j);
            }
        }
    }
    vector parent(n, vector<pair<int, int>>(m));
    queue<pair<int, int>> frontier;
    frontier.push(startPos);
    vector<int> x_movement = {0, 0, 1, -1}, y_movement = {1, -1, 0, 0};
    while (!frontier.empty()) {
        pair<int, int> pos = frontier.front();
        frontier.pop();
        if (pos == endPos) {
            break;
        }
        for (int i = 0; i < 4; i++) {
            if ((pos.first+x_movement[i] < 0 || pos.first+x_movement[i] >= n) || (pos.second+y_movement[i] < 0 || pos.second+y_movement[i] >= m)) {
                continue;
            }
            if (board[pos.first+x_movement[i]][pos.second+y_movement[i]] != '#' &&
            parent[pos.first+x_movement[i]][pos.second+y_movement[i]] == make_pair(0, 0)) {
                parent[pos.first+x_movement[i]][pos.second+y_movement[i]] = make_pair(pos.first, pos.second);
                frontier.emplace(pos.first+x_movement[i], pos.second+y_movement[i]);
            }
        }
    }
    if (parent[endPos.first][endPos.second] == make_pair(0, 0)) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    pair<int, int> curr = endPos;
    string ans;
    while (curr != startPos) {
        pair<int, int> temp = parent[curr.first][curr.second];
        if (temp.first > curr.first) {
            ans.insert(0, 1, 'U');
        } else if (temp.first < curr.first) {
            ans.insert(0, 1, 'D');
        } else if (temp.second > curr.second) {
            ans.insert(0, 1, 'L');
        } else {
            ans.insert(0, 1, 'R');
        }
        curr = temp;
    }
    cout << ans.size() << endl;
    cout << ans << endl;
    return 0;
}