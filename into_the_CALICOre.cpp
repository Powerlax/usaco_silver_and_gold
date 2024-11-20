//
// Created by innav_z3e3dq9 on 11/16/2024.
//

#include <bits/stdc++.h>
using namespace std;

struct Path {
    int x, y, actions;
    bool hair;
};

bool equals(const Path &a, const Path &b) {
    return (a.x == b.x && a.y == b.y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    vector<pair<int, int>> options = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<string> grid(n);
        Path start{}, end{};
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
            int pos = static_cast<int>(grid[i].find('S'));
            if (pos != string::npos) {
                start = {i, pos, 0, true};
            }
            pos = static_cast<int>(grid[i].find('E'));
            if (pos != string::npos) {
                end = {i, pos, 0, true};
            }
        }
        vector<vector<bool>> visited(n, vector<bool>(m));
        queue<Path> frontier;
        frontier.push(start);
        bool solved = false;
        while (!frontier.empty()) {
            auto path = frontier.front();
            frontier.pop();
            if (equals(path,end)) {
                cout << path.actions << endl;
                solved = true;
                break;
            }
            visited[path.x][path.y] = true;
            bool asdf = false;
            if (grid[path.x][path.y] == '*') {
                asdf = true;
            }
            for (auto [fst, snd] : options) {
                if (!(path.x+fst < 0 || path.x+fst >= n) &&
                    !(path.y+snd < 0 || path.y+snd >= m) &&
                    !visited[path.x+fst][path.y+snd] &&
                    grid[path.x+fst][path.y+snd] != '#') {
                    auto new_path = path;
                    new_path.x += fst;
                    new_path.y += snd;
                    new_path.actions++;
                    frontier.push(new_path);
                }
                if (path.hair) {
                    bool found_crystal = false;
                    auto new_path = path;
                    new_path.hair = false;
                    for (int i = 0; i < k; i++) {
                        if (!(new_path.x+fst < 0 || new_path.x+fst >= n) &&
                            !(new_path.y+snd < 0 || new_path.y+snd >= m)) {
                            if (grid[new_path.x+fst][new_path.y+snd] != '#') {
                                new_path.x += fst;
                                new_path.y += snd;
                                if (grid[new_path.x+fst][new_path.y+snd] == '*') {
                                    found_crystal = true;
                                }
                            } else {
                                new_path.actions++;
                                if (found_crystal || asdf) {
                                    new_path.hair = true;
                                }
                                frontier.push(new_path);
                                break;
                            }
                        } else {
                            new_path.actions++;
                            if (found_crystal || asdf) {
                                new_path.hair = true;
                            }
                            frontier.push(new_path);
                            break;
                        }
                    }
                    new_path.actions++;
                    if (found_crystal) {
                        new_path.hair = true;
                    }
                    frontier.push(new_path);
                }
            }
        }
        if (!solved) {
            cout << -1 << endl;
        }
    }
    return 0;
}
