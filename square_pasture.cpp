//
// Created by innav_z3e3dq9 on 11/17/2024.
//

#include <bits/stdc++.h>
using namespace std;

int n;
long long ans, eq;
vector<pair<long long, long long>> cows;

void calc() {
    sort(cows.begin()+1, cows.begin()+n+1);
    for (int i = 1; i <= n; i++) {
        vector<long long> boxes;
        int m = 0;
        for (int j = i; j <= n; j++) {
            boxes.push_back(cows[j].second);
            m++;
            const long long len = cows[j].first - cows[i].first;
            const long long min_pos = max(cows[i].second, cows[j].second) - len;
            const long long max_pos = min(cows[i].second, cows[j].second);
            if (min_pos > max_pos) {
                continue;
            }
            sort(boxes.begin(), boxes.end());
            int index1 = 0, index2 = -1;
            for(int cur = static_cast<int>(min_pos); cur <= max_pos; cur++) {
                while (index1 < m && boxes[index1] < cur) {
                    index1++;
                }
                while (index2 < m-1 && boxes[index2+1] <= cur+len) {
                    index2++;
                }
                if (boxes[index2] - boxes[index1] == len) {
                    ++eq;
                } else {
                    ++ans;
                }
                if (index2 == m-1) {
                    cur += static_cast<int>(boxes[index1]) - cur;
                } else {
                    cur += static_cast<int>(min(boxes[index1] - cur, boxes[index2 + 1] - cur - len - 1));
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);cin >> n;
    cows.resize(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> cows[i].first >> cows[i].second;
    }
    calc();
    for(int i = 1; i <= n; i++) {
        swap(cows[i].first, cows[i].second);
    }
    calc();
    cout << ans + eq / 2 + 1;
    return 0;
}
