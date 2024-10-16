//
// Created by innav_z3e3dq9 on 9/7/2024.
//

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
const ll MOD = 1e9 + 7;

int main() {
	freopen("help.in", "r", stdin);
	int n;
	cin >> n;
	vi a(2 * n + 1, 0);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		a[x]++;
		a[y]--;
	}
	vl pow(n);
	pow[0] = 1;
	for (int i = 1; i <= n - 1; i++) { pow[i] = pow[i - 1] * 2 % MOD; }
	int open_segs_num = 0;
	ll ans = 0;
	for (int i = 1; i <= 2 * n; i++) {
		open_segs_num += a[i];
		if (a[i] == 1) { ans = (ans + pow[n - open_segs_num]) % MOD; }
	}
	freopen("help.out", "w", stdout);
	cout << ans << endl;
}