//
// Created by innav_z3e3dq9 on 11/16/2024.
//

#include <bits/stdc++.h>
using namespace std;

struct Coord {
    int x, y;
};

bool comp(const Coord &a, const Coord &b) {
    if (a.x+a.y == b.x+b.y) {
        return a.x < b.x;
    }
    return a.x+a.y < b.x+b.y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    set<double> angles;
    vector<Coord> coords;
    constexpr int threshold = 2000;
    for (int i = 1; i < threshold; i++) {
        for (int j = 1; j < threshold; j++) {
            if (const double theta = static_cast<double>(i)/static_cast<double>(j); angles.find(theta) == angles.end()) {
                coords.push_back({i, j});
                angles.insert(theta);
            }
        }
    }
    sort(coords.begin(), coords.end(), comp);
    while (t--) {
        int q;
        cin >> q;
        q--;
        cout << coords[q].x << " " << coords[q].y << endl;
    }
    return 0;
}
