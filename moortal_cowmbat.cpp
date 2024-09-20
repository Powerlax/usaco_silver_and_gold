//
// Created by innav_z3e3dq9 on 9/17/2024.
//
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
const int MAXL = 26;
int freq[MAXN][MAXL];

int count(int start, int end, int let) {
	return freq[end + 1][let] - freq[start][let];
}

int main() {
	freopen("cowmbat.in", "r", stdin);  // see /general/input-output
	freopen("cowmbat.out", "w", stdout);
	int n;
	int m;
	int k;
	cin >> n >> m >> k;
	string s;
	cin >> s;
	vector days(m, vector<int>(m));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) { cin >> days[i][j]; }
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			for (int l = 0; l < m; l++) {
				days[j][l] = min(days[j][l], days[j][i] + days[i][l]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			freq[i][j] = freq[i - 1][j];
		}
		freq[i][s[i - 1] - 'a']++;
	}
	vector dp(n, vector(m, INT_MAX));
	vector ans(n, INT_MAX);
	ans[0] = 0;
	for (int idx = k - 1; (idx < 2 * k - 1) && (idx < n); idx++) {
		for (int let = 0; let < m; let++) {
			dp[idx][let] = 0;
			for (int i = 0; i < m; i++) {
				dp[idx][let] += (days[i][let] * count(0, idx, i));
			}
		}
		ans[idx] = dp[idx][0];
		for (int j = 1; j < m; j++) {
			ans[idx] = min(ans[idx], dp[idx][j]);
		}
	}
	for (int idx = (2 * k - 1); idx < n; idx++) {
		for (int j = 0; j < m; j++) {
			dp[idx][j] = dp[idx - 1][j];
			if (s[idx] - 'a' != j) {
				dp[idx][j] += days[s[idx] - 'a'][j];
			}
		}
		for (int let1 = 0; let1 < m; let1++) {
			int add = 0;
			for (int let2 = 0; let2 < m; let2++) {
				add += days[let2][let1] * count(idx - k + 1, idx, let2);
			}
			dp[idx][let1] = min(dp[idx][let1], ans[idx - k] + add);
		}
		ans[idx] = dp[idx][0];
		for (int j = 1; j < m; j++) {
			ans[idx] = min(ans[idx], dp[idx][j]);
		}
	}
	cout << ans[n - 1] << endl;
}