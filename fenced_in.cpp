//
// Created by innav_z3e3dq9 on 11/22/2024.
//

#include <bits/stdc++.h>
using namespace std;

struct Edge {
	int cost;
	int i;
	int j;
};

bool comp(const Edge &t, const Edge &y) {
	return t.cost < y.cost;
}

class DisjointSets {
	vector<int> parents;
	vector<int> sizes;

public:
	explicit DisjointSets(const int n) : parents(n, -1), sizes(n, 1) {}

	int find(const int x) {
		if (parents[x] == x || parents[x] == -1) {
			return x;
		}
		return parents[x] = find(parents[x]);
	}

	bool unite(const int x, const int y) {
		int x_root = find(x);
		int y_root = find(y);
		if (x_root == y_root) {
			return false;
		}
		if (sizes[x_root] < sizes[y_root]) {
			swap(x_root, y_root);
		}
		sizes[x] += sizes[y];
		parents[y] = x;
		return true;
	}

	bool connected(const int a, const int b) {
		return find(a) == find(b);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	//freopen("fencedin.in", "r", stdin);
	//freopen("fencedin.out", "w", stdout);
	int a, b, n, m;
	cin >> a >> b >> n >> m;
	vector<int> vx(n + 1), vy(m + 1);
	for (int i = 1; i <= n; i++) {
		cin >> vx[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> vy[i];
	}
	vx.push_back(a);
	vy.push_back(b);
	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());
	n += 2;
	m += 2;
	vector<Edge> edges;
	int curr_sect = 0, row = 1;
	while (row < m) {
		for (int i = 0; i < n - 2; i++) {
			edges.push_back(Edge{vy[row] - vy[row - 1], curr_sect, curr_sect + 1});
			curr_sect++;
		}
		curr_sect++;
		row++;
	}
	curr_sect = n - 1;
	int col = 1;
	while (col < n) {
		const int init = curr_sect;
		for (int i = 0; i < m - 2; i++) {
			edges.push_back(Edge{vx[col] - vx[col - 1], curr_sect - (n - 1), curr_sect});
			curr_sect += (n - 1);
		}
		curr_sect = init + 1;
		col++;
	}
	DisjointSets dsu((n + 2) * (m + 2));
	sort(edges.begin(), edges.end(), comp);
	long long ans = 0;
	for (const auto &[cost, i, j] : edges) {
		if (dsu.unite(i, j)) {
			ans += cost;
		}
	}
	cout << ans << endl;
}