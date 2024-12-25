//
// Created by innav_z3e3dq9 on 11/30/2024.
//

#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<vector<char>> board;
vector<vector<bool>> visited;
vector<pair<int, int>> components;

int floodfill(int i, int j, const char color) {
	int ans = 1;
	if (i < 0 || j < 0 || i >= n || j >= 10 || visited[i][j] || board[i][j] != color) {
		return 0;
	}
	visited[i][j] = true;
	components.push_back({i, j});
	ans += floodfill(i + 1, j, color) + floodfill(i - 1, j, color) +
		   floodfill(i, j + 1, color) + floodfill(i, j - 1, color);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("mooyomooyo.in", "r", stdin);
	freopen("mooyomooyo.out", "w", stdout);
	cin >> n >> k;
	board.resize(n, vector<char>(10));
	for (int i = n - 1; i >= 0; i--) {
		string row;
		cin >> row;
		for (int j = 0; j < 10; j++) {
			board[i][j] = row[j];
		}
	}
	visited = vector(n, vector<bool>(10));
	bool board_changed = true;
	while (board_changed) {
		board_changed = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 10; j++) {
				if (!visited[i][j] && board[i][j] != '0') {
					const char current_color = board[i][j];
					if (const int connected_max = floodfill(i, j, current_color); connected_max >= k) {
						board_changed = true;
						for (auto [fst, snd] : components) {
							board[fst][snd] = '0';
						}
					}
					components.clear();
				}
			}
		}
		for (int col = 0; col < 10; col++) {
			vector<char> column_after_gravity;
			for (int row = 0; row < n; row++) {
				if (board[row][col] != '0') {
					column_after_gravity.push_back(board[row][col]);
				}
			}
			for (int row = 0; row < n; row++) {
				if (row < column_after_gravity.size()) {
					board[row][col] = column_after_gravity[row];
				} else {
					board[row][col] = '0';
				}
			}
		}
		fill(visited.begin(), visited.end(), vector<bool>(10));
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < 10; j++) {
			cout << board[i][j];
		}
		cout << endl;
	}
}