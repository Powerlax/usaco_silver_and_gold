//
// Created by innav_z3e3dq9 on 8/8/2024.
//

#include <bits/stdc++.h>
using namespace std;

struct Road {
    int sr, sc;
    int er, ec;
};

inline bool operator<(const Road &r1, const Road &r2) {
    return tie(r1.sr, r1.sc, r1.er, r1.ec) < tie(r2.sr, r2.sc, r2.er, r2.ec);
}

vector<pair<int, int>> neighbors(int r, int c) {
    return {{r + 1, c}, {r - 1, c}, {r, c + 1}, {r, c - 1}};
}

int main() {
    freopen("countcross.in", "r", stdin);
    int side_len;
    int cow_num;
    int road_num;
    cin >> side_len >> cow_num >> road_num;
    set<Road> roads;
    for (int r = 0; r < road_num; r++) {
        int sr, sc;
        int er, ec;
        cin >> sr >> sc >> er >> ec;
        roads.insert(Road{--sr, --sc, --er, --ec});
        roads.insert(Road{er, ec, sr, sc});
    }
    vector<vector<bool>> has_cow(side_len, vector<bool>(side_len));
    for (int cow = 0; cow < cow_num; cow++) {
        int r, c;
        cin >> r >> c;
        has_cow[--r][--c] = true;
    }
    vector<vector<bool>> visited(side_len, vector<bool>(side_len));
    function<int(int, int, int, int)> connected_cow_num;
    connected_cow_num = [&](int r, int c, int prev_r, int prev_c) -> int {
        if (r < 0 || c < 0 || r >= side_len ||
            c >= side_len
            || visited[r][c]
            || roads.count(Road{r, c, prev_r, prev_c})) {
            return 0;
        }
        visited[r][c] = true;
        int cow_num = has_cow[r][c];
        for (const auto &[nr, nc] : neighbors(r, c)) {
            cow_num += connected_cow_num(nr, nc, r, c);
        }
        return cow_num;
    };
    vector<int> cow_components;
    for (int r = 0; r < side_len; r++) {
        for (int c = 0; c < side_len; c++) {
            if (!visited[r][c]) {
                int comp_sz = connected_cow_num(r, c, r, c);
                if (comp_sz != 0) { cow_components.push_back(comp_sz); }
            }
        }
    }
    int distant_pairs = 0;
    for (int i = 0; i < cow_components.size(); i++) {
        for (int j = i + 1; j < cow_components.size(); j++) {
            distant_pairs += cow_components[i] * cow_components[j];
        }
    }
    freopen("countcross.out", "w", stdout);
    cout << distant_pairs << endl;
}