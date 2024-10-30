//
// Created by innav_z3e3dq9 on 10/19/2024.
//
#include <bits/stdc++.h>

using namespace std;

vector dp(19, vector(50, vector(2, vector<long long>(2))));
string num;

void reset() {
	for (auto &i : dp) {
		for (auto &j : i) {
			for (auto &k : j) {
				for (auto &l : k) {
					l = -1;
				}
			}
		}
	}
}

long long solve_dp(const int pos, const int k, const bool under, const bool started, const int target, const int target2) {
	if (pos == num.size()) {
		if (!started) { return 0; }
		if (target2 != -1) {
			if (k == 20) {
				return 1;
			}
			return 0;
		}
		if (k >= 20) {
			return 1;
		}
		return 0;
	}
	if (dp[pos][k][under][started] != -1) {
		return dp[pos][k][under][started];
	}
	long long ans = 0;
	for (int i = 0; i <= 9; i++) {
		const int digit_diff = num[pos] - '0';
		if (!under && i > digit_diff) {
			break;
		}
		bool is_under = under;
		if (i < digit_diff) {
			is_under = true;
		}
		const bool is_started = (started || i != 0);
		if (is_started && target2 != -1 && i != target && i != target2) {
			continue;
		}
		int new_k = k;
		if (is_started) {
			if (target == i) {
				new_k = k + 1;
			} else {
				new_k = k - 1;
			}
		}
		ans += solve_dp(pos + 1, new_k, is_under, is_started, target, target2);
	}
	return dp[pos][k][under][started] = ans;
}

long long count_interesting_to(const long long bound) {
	num = to_string(bound);
	long long ans = 0;
	for (int i = 0; i <= 9; i++) {
		reset();
		ans += solve_dp(0, 20, false, false, i, -1);
	}
	long long duplicates = 0;
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			reset();
			duplicates += solve_dp(0, 20, false, false, i, j);
		}
	}
	return ans - (duplicates / 2);
}

int main() {
	freopen("odometer.in", "r", stdin);
	freopen("odometer.out", "w", stdout);
	long long x, y;
	cin >> x >> y;
	cout << count_interesting_to(y) - count_interesting_to(x - 1) << endl;
}