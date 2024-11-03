//
// Created by innav_z3e3dq9 on 7/8/2024.
//

#include <bits/stdc++.h>
using namespace std;

const long long inf = 1e17;
const long long MAXM = 1e5;
vector<long long> factors[MAXM + 5];

void init() {
    for (long long i = 1; i <= MAXM; i++) {
        for (long long j = i; j <= MAXM; j += i) {
            factors[j].push_back(i);
        }
    }
}

void solve() {
    long long n, m;
    cin >> n >> m;
    vector<pair<long long, long long>> vec;
    for (long long i = 0; i < n; i++) {
        long long value;
        cin >> value;
        vec.push_back({value, i});
    }
    sort(vec.begin(), vec.end());
    vector<long long> frequency(m + 5, 0);
    long long curr_count = 0;
    long long j = 0;
    long long global_ans = inf;
    for (long long i = 0; i < n; i++) {
        for (auto x : factors[vec[i].first]) {
            if (x > m) {
                break;
            }
            if (!frequency[x]++) {
                curr_count++;
            }
        }
        while (curr_count == m) {
            long long curr_ans = vec[i].first - vec[j].first;
            if (curr_ans < global_ans) {
                global_ans = curr_ans;
            }
            for (auto x : factors[vec[j].first]) {
                if (x > m) {
                    break;
                }
                if (--frequency[x] == 0){
                    curr_count--;
                }
            }
            j++;
        }
    }
    cout << (global_ans >= inf ? -1 : global_ans) << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}