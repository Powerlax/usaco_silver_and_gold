//
// Created by innav_z3e3dq9 on 8/25/2024.
//

#include <bits/stdc++.h>
using namespace std;

struct Cow {
	pair<int, int> coord;
	int id;
};

bool comp(const Cow a, const Cow b) {
	if (a.coord.first == b.coord.first) {
		return a.coord.second < b.coord.second;
	}
	return a.coord.first < b.coord.first;
}

bool comp2(const Cow a, const Cow b) {
	if (a.coord.second == b.coord.second) {
		return a.coord.first < b.coord.first;
	}
	return a.coord.second < b.coord.second;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<Cow> cows_north;
	vector<Cow> cows_east;
	for (int i = 0; i<n; i++) {
		int x, y;
		char a;
		cin >> a >> x >> y;
		pair<int, int> coord = {x, y};
		if (a == 'N') {
			cows_north.push_back({coord, i});
		} else {
			cows_east.push_back({coord, i});
		}
	}
	sort(cows_north.begin(), cows_north.end(), comp);
	sort(cows_east.begin(), cows_east.end(), comp2);
	vector stopped(n, false);
	vector blame(n, 0);
	for (auto i : cows_east) {
		for (auto j : cows_north) {
			if (!stopped[i.id] && !stopped[j.id] &&
			    i.coord.second >= j.coord.second &&
			    i.coord.first <= j.coord.first) {
				int x_length = j.coord.first - i.coord.first;
				int y_length = i.coord.second - j.coord.second;
				if (y_length < x_length) {
					stopped[i.id] = true;
					blame[j.id] += 1 + blame[i.id];
				} else if (y_length > x_length) {
					stopped[j.id] = true;
					blame[i.id] += 1 + blame[j.id];
				}
			}
		}
	}
	for (int i = 0; i<n; i++) {
		cout << blame[i] << endl;
	}
}