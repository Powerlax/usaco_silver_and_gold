//
// Created by innav_z3e3dq9 on 8/29/2024.
//

#include <bits/stdc++.h>
using namespace std;

map<int, long long> dp;

long long factorial(int k) {
    if (k == 0 || k == 1) {
        return 1;
    }
    if (dp.count(k)) {
        return dp[k];
    }
    dp[k] = k * factorial(k - 1);
    return dp[k];
}
long long exp(long long x, long long n, long long m) {
	x %= m;
	long long res = 1;
	while (n > 0) {
		if (n % 2 == 1) { res = res * x % m; }
		x = x * x % m;
		n /= 2;
	}
	return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int,int>> arr(n);
    int largest = -1;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
        largest = max(largest, arr[i].first);
    }
    factorial(largest);
    for (int i = 0; i<n; i++) {
        cout << ((factorial(arr[i].first))/
            (factorial(arr[i].second)*factorial(arr[i].first-arr[i].second)))%1000000007 << endl;
    }
    return 0;
}