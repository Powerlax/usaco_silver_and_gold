//
// Created by innav_z3e3dq9 on 2/8/2025.
//

#include <asyncinfo.h>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> position(n);
        for (int i = 0; i < n; i++) {
            cin >> position[i];
        }
        vector<int> speed(n);
        for (int i = 0; i < n; i++) {
            cin >> speed[i];
        }
        vector<int> ans(n);
        for (int i = 0; i < n / 2; i++) {
            int min_time = INT_MAX;
            int a = -1, b = -1;
            for (int j = 0; j < n; j += 2) {
                if (speed[j] < 0) {
                    continue;
                }
                long long dist = position[j + 1] - position[j];
                long long speed_sum = speed[j] + speed[j + 1];
                long long meeting_time = 2 * ((dist + speed_sum - 1) / speed_sum) - (j % 2 == 0);
                if (meeting_time < min_time) {
                    min_time = meeting_time;
                    a = j;
                    b = j + 1;
                }
            }
            speed[a] = -1;
            speed[b] = -1;
            ans[a] = min_time;
            ans[b] = min_time;
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}