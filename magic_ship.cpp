//
// Created by innav_z3e3dq9 on 8/1/2024.
//

#include <bits/stdc++.h>
using namespace std;

bool valid = false;

long long first_true(long long lo, long long hi, function<bool(long long)> f) {
    hi++;
    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        cout << mid << " " << f(mid) << endl;
        if (f(mid)) {
            valid = true;
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int init_x, init_y;
    cin >> init_x >> init_y;
    int goal_x, goal_y;
    cin >> goal_x >> goal_y;
    int n;
    cin >> n;
    string wind;
    cin >> wind;
    vector<pair<int, int>> loc;
    int x = 0, y = 0;
    for (char a : wind) {
        if (a == 'U') {
            y++;
        } else if (a == 'D') {
            y--;
        } else if (a == 'R') {
            x++;
        } else {
            x--;
        }
    }
    long long ans = first_true(1, INT64_MAX/2, [&](long long days){
        long long wind_x = (days/n) * x;
        long long wind_y = (days/n) * y;
        long long left_over = days % n;
        for (int i = 0; i<left_over; i++) {
            if (wind[i] == 'U') {
                init_y++;
            } else if (wind[i] == 'D') {
                init_y--;
            } else if (wind[i] == 'R') {
                init_x++;
            } else {
                init_x--;
            }
        }
        return abs(init_x + wind_x - goal_x) + abs(init_y + wind_y - goal_y) <= days;
    });
    if (!valid) {
        cout << -1;
    } else {
        cout << ans;
    }
    return 0;
}