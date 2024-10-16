//
// Created by innav_z3e3dq9 on 9/2/2024.
//
#include <bits/stdc++.h>
using namespace std;

int source_node;
bool cycle_found = false, cycle_candidate = true;
vector<int> connections;
vector<int> nodes_in;
vector<bool> visited;

int char_to_int(char a) {
	return (a >= 'a' ? a - 'a' : a - 'A' + 26);
}

void dfs(int curr_node) {
	if (nodes_in[curr_node] != 1) {
		cycle_candidate = false;
	}
	visited[curr_node] = true;
	if (connections[curr_node] == source_node && curr_node != source_node) {
		cycle_found = true;
	}
	if (connections[curr_node] != -1) {
		if (!visited[connections[curr_node]]) {
			dfs(connections[curr_node]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--) {
		bool good = true;
		connections = vector(52, -1);
		nodes_in = vector(52, 0);
		visited = vector(52, false);
		string get, target;
		int ans = 0;
		cin >> get >> target;
		set<char> check;
		for (int i = 0; i < get.size(); i++) {
			if (connections[char_to_int(get[i])] != -1 && connections[char_to_int(get[i])] != char_to_int(target[i])) {
				cout << -1 << endl;
				good = false;
				break;
			}
			connections[char_to_int(get[i])] = char_to_int(target[i]);
			check.insert(target[i]);
		}
		if (!good) {
			continue;
		}
		if (check.size() == 52) {
			cout << (get == target ? 0 : -1) << endl;
			good = false;
		}
		if (!good) {
			continue;
		}
		for (int x = 0; x < 52; x++) {
			if (connections[x] != -1 && connections[x] != x) {
				nodes_in[connections[x]]++;
				ans++;
			}
		}
		for (source_node = 0; source_node < 52; source_node++) {
			cycle_found = false, cycle_candidate = true;
			dfs(source_node);
			ans += (cycle_found && cycle_candidate);
		}
		cout << ans << endl;
	}
}