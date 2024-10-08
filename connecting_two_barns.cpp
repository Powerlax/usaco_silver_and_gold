//
// Created by innav_z3e3dq9 on 8/21/2024.
//
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<vector<int>> comps;
vector<int> comp;

void dfs(int curr, int color) {
	if (comp[curr] != -1) {
		return;
	}
	comp[curr] = color;
	for (int u : adj[curr]) {
		dfs(u, color);
	}
}

long long cost(int a, int b, int n) {
	int dist = n+1;
	for (int u : comps[a]) {
		int i = lower_bound(comps[b].begin(), comps[b].end(), u) - comps[b].begin();
		if (i > 0) {
			dist = min(dist, abs(comps[b][i - 1] - u));
		}
		if (i < comps[b].size()) {
			dist = min(dist, abs(comps[b][i] - u));
		}
	}
	return (long long)(dist * dist);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		adj = vector<vector<int>>(n);
		comps = vector<vector<int>>(n);
		for (int i = 0; i < n; i++) {
			comp[i] = -1;
			adj[i].clear();
			comps[i].clear();
		}
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			adj[--a].push_back(--b);
			adj[b].push_back(a);
		}
		int cur = -1;
		comp = vector<int>(n, -1);
		for (int i = 0; i < n; i++) {
			if (comp[i] == -1) {
				dfs(i, ++cur);
			}
		}
		for (int i = 0; i < n; i++) {
			comps[comp[i]].push_back(i);
		}
		long long res = cost(comp[0], comp[n - 1], n);
		for (int c = 1; c < cur; c++) {
			res = min(res, cost(c, comp[0], n) + cost(c, comp[n - 1], n));
		}
		cout << res << endl;
	}
}