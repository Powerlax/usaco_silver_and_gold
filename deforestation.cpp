//
// Created by innav_z3e3dq9 on 12/22/2024.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        int n, k;
        std::cin >> n >> k;
        std::vector<int> x(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> x[i];
        }
        std::sort(x.begin(), x.end());

        std::vector<std::tuple<int, int, int, int>> events;
        for (int i : x) {
            events.emplace_back(i, 0, 0, 0);
        }

        for (int i = 0; i < k; ++i) {
            int l, r, t;
            std::cin >> l >> r >> t;
            int existing = std::upper_bound(x.begin(), x.end(), r) - std::lower_bound(x.begin(), x.end(), l);
            events.emplace_back(l, -1, r, existing - t);
        }

        std::sort(events.begin(), events.end());

        std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<>> pq;
        long long ans = 0;

        for (const auto& event : events) {
            int l, tp, r, cut;
            std::tie(l, tp, r, cut) = event;

            if (tp == -1) {
                pq.emplace(ans + cut, r);
            } else {
                while (!pq.empty() && pq.top().second < l) {
                    pq.pop();
                }
                if (pq.empty() || pq.top().first != ans) {
                    ans++;
                }
            }
        }

        std::cout << ans << std::endl;
    }

    return 0;
}