//
// Created by innav_z3e3dq9 on 8/25/2024.
//

#include <bits/stdc++.h>
using namespace std;

bool sort_y(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
	set<int> diff_x, diff_y;
    vector<pair<int, int>> pos;
    for (int i = 0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        pos.emplace_back(x, y);
		diff_x.insert(x);
    	diff_y.insert(y);
    }
	sort(pos.begin(), pos.end());
	for (int i = 0; i<n; i++) {
		pos[i].first = i;
	}
	sort(pos.begin(), pos.end(), sort_y);
	map<int, int> new_y;
	for (int i = 0; i<n; i++) {
		pos[i].second = i;
	}
	sort(pos.begin(), pos.end());
	vector<vector<int>> below(n, vector<int>(n+1)), above(n, vector<int>(n+1));
	for (int i = 0; i<n; i++) {
		int y = pos[i].second;
		for (int j = 0; j<n+1; j++) {
			below[y][j] = (below[y][j - 1] + (pos[j - 1].second < y));
			above[y][j] = (above[y][j - 1] + (pos[j - 1].second > y));
		}
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int bottom = min(pos[i].second, pos[j].second);
			int bottom_ans = below[bottom][j + 1] - below[bottom][i] + 1;
			int top = max(pos[i].second, pos[j].second);
			int top_ans = above[top][j + 1] - above[top][i] + 1;
			ans += (bottom_ans * top_ans);
		}
	}
	cout << ans+n+1 << endl;
    return 0;
}
