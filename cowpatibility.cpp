//
// Created by innav_z3e3dq9 on 9/7/2024.
//

#include <bits/stdc++.h>
using namespace std;


int main() {
	freopen("cowpatibility.in", "r", stdin);
	freopen("cowpatibility.out", "w", stdout);
	int n;
	cin >> n;
	vector<array<int, 5>> cows(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> cows[i][j];
		}
		sort(cows[i].begin(), cows[i].end());
	}
	vector<map<array<int, 5>, int>> common(5);
	for (int i = 0; i < n; i++) {
		common[4][cows[i]]++;
		for (int a = 0; a < 5; a++) {
			common[0][{cows[i][a]}]++;
			for (int b = a + 1; b < 5; b++) {
				common[1][{cows[i][a], cows[i][b]}]++;
				for (int c = b + 1; c < 5; c++) {
					common[2][{cows[i][a], cows[i][b], cows[i][c]}]++;
					for (int d = c + 1; d < 5; d++) {
						common[3][{cows[i][a], cows[i][b], cows[i][c], cows[i][d]}]++;
					}
				}
			}
		}
	}
	long long compatible = 0;
	for (int i = 0; i < 5; i++) {
		for (auto &[k, v] : common[i]) {
			if (i % 2 == 0) {
				compatible += static_cast<long long>(v) * (v - 1) / 2;
			} else {
				compatible -= static_cast<long long>(v) * (v - 1) / 2;
			}
		}
	}
	cout << (n * (n - 1) / 2) - compatible << endl;
}