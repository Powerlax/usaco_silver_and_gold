//
// Created by innav_z3e3dq9 on 9/2/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, t = 0, pos = 0;
    cin >> n;
    vector<int> counts(n);
    for (int i = 0; i < n; i++) {
        cin >> counts[i];
    	t += counts[i];
    }
    bool going_right = true;
	string route;
	for (int i = 0; i<t; i++) {
		if (pos == 0) {
			going_right = true;
		} else if (pos == n) {
			going_right = false;
		} else if (counts[pos] >= counts[pos - 1]) {
			going_right = true;
		} else {
			going_right = false;
		}
		route.push_back(going_right ? 'R' : 'L');
		if (going_right) {
			counts[pos]--;
			pos++;
		} else {
			pos--;
			counts[pos]--;
		}
	}
	cout << route << endl;
    return 0;
}