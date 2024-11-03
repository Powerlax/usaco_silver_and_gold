//
// Created by innav_z3e3dq9 on 8/12/2024.
//

#include <bits/stdc++.h>
using namespace std;

map<int, int> point;

int succ(int node) {
    return point[node];
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i<n; i++) {
        int a;
        cin >> a;
        a--;
        point[i] = a;
    }
    for (int i = 0; i<n; i++) {
        set<int> visited;
        int old = -1;
        int next_to_visit = i;
        while (old != visited.size()) {
            old = visited.size();
            int a = succ(next_to_visit);
            visited.insert(a);
            next_to_visit = a;
        }
        cout << visited.size() << " ";
    }
    return 0;
}