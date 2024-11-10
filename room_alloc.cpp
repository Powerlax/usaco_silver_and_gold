//
// Created by innav_z3e3dq9 on 7/12/2024.
//

#include <bits/stdc++.h>
using namespace std;

struct Guest {
    int a, b, room;
};

bool comp(Guest x, Guest b) {return x.a < b.a;}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<Guest> guests;
    for (int i = 0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        guests.push_back({a, b});
    }
    sort(guests.begin(), guests.end(), comp);
    priority_queue<int, vector<int>, greater<int>> departures;
    int rooms = 0;
    for (int i = 0; i<n; i++) {

    }
    return 0;
}