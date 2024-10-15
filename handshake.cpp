//
// Created by innav_z3e3dq9 on 8/16/2024.
//

#include <bits/stdc++.h>
using namespace std;

int n;
long long m;
vector<int> power;
vector<long long> prefix;

pair<long long, long long> handshake_and_happiness_count(int min_handshake) {
    long long total_handshake = 0, total_happiness = 0;
    for (int center = 0; center < n; ++center) {
        if (power[center] + power[n - 1] < min_handshake) {
            continue;
        }
        int l = center, r = n-1;
        while (l < r) {
            int index = l + (r - l) / 2;
            if (power[center] + power[index] >= min_handshake) r = index;
            else l = index + 1;
        }
        total_handshake += 2 * (n-l);
        if (l == center) total_handshake -= 1;

        total_happiness += 2ll * (n-l) * power[center] + 2 * (prefix[n] - prefix[l]);
        if (l == center) {
            total_happiness -= 2 * power[center];
        }
    }
    return {total_handshake, total_happiness};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> power[i];
    sort(power.begin(), power.end());
    for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + power[i];
    int l = 0, r = n;
    while (l < r) {
        int min_handshake  = l + (r - l + 1) / 2;
        auto result = handshake_and_happiness_count(min_handshake);
        if (result.first >= m) l = min_handshake;
        else r = min_handshake - 1;
    }
    auto result = handshake_and_happiness_count(l);
    for (long long i = result.first; i > m; --i) result.second -= l;
    cout << result.second << '\n';
}