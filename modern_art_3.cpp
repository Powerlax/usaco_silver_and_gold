//
// Created by innav_z3e3dq9 on 10/15/2024.
//

#include <bits/stdc++.h>
using namespace std;

int find_first(const vector<int> &painting, const int target) {
    for (int i = 0; i<painting.size(); i++) {
        if (painting[i] == target) {
            return i;
        }
    }
    return -1;
}

int find_last(const vector<int> &painting, const int target) {
    for (int i = painting.size(); i >= 0; i--) {
        if (painting[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> painting(n);
    for (int i = 0; i<n; i++) {
        cin >> painting[i];
    }
    vector<int> my_painting(n);
    for (int i = 0; i<n; i++) {

    }
    return 0;
}