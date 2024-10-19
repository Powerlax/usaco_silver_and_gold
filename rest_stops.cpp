//
// Created by innav_z3e3dq9 on 10/18/2024.
//

#include <bits/stdc++.h>
using namespace std;

struct RestStop {
    int distance, tastiness;
};

bool comp(const RestStop &a, const RestStop &b) {
    return a.tastiness < b.tastiness;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);
    int l, n, farmer_speed, bessie_speed;
    cin >> l >> n >> farmer_speed >> bessie_speed;
    vector<RestStop> rest_stops(n);
    for (int i = 0; i < n; i++) {
        cin >> rest_stops[i].distance >> rest_stops[i].tastiness;
    }
    vector<bool> stop(n);
    int best = 0;
    for (int i = n-1; i >= 0; i--) {
        if (best < rest_stops[i].tastiness) {
            stop[i] = true;
            best = rest_stops[i].tastiness;
        }
    }
    int total_stops = 0;
    for (int i = 0; i < n; i++) {
        if (stop[i]) {
            total_stops++;
        }
    }
    int last_stop = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (stop[i]) {
            const long long dist = rest_stops[i].distance - last_stop;
            last_stop = rest_stops[i].distance;
            const long long john = dist * farmer_speed;
            const long long bessie = dist * bessie_speed;
            const long long diff = john - bessie;
            ans += diff * rest_stops[i].tastiness;
        }
    }
    cout << ans << endl;
    return 0;
}