//
// Created by innav_z3e3dq9 on 8/21/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> intervals(n);
	for (auto i : intervals) {
		cin >> i.first >> i.second;
	}
	vector<long long> start(2 * m + 1), end(2 * m + 1), a_freq(m + 1), b_freq(m + 1);
	for (int i = 0; i < n; i++) {
          a_freq[intervals[i].first]++;
    }
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= m; j++) {
			start[i + j] += a_freq[i] * a_freq[j];
        }
    }
	for (int i = 0; i < n; i++) {
		b_freq[intervals[i].second]++;
    }
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= m; j++) {
			end[i + j] += b_freq[i] * b_freq[j];
        }
    }
	long long prefix_sum = 0;
	for (int i = 0; i <= 2 * m; i++) {
		prefix_sum += start[i];
		cout << prefix_sum << "\n";
		prefix_sum -= end[i];
	}
}