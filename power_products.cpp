//
// Created by innav_z3e3dq9 on 8/24/2024.
//

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int k;

vector<pair<int, int>> factor(int number) {
	map<int, int> factors;
	for (int i = 2; i * i <= number; i++) {
		while (number % i == 0) {
			number /= i;
			factors[i]++;
		}
	}
	if (number > 1) { factors[number]++; }
	vector<pair<int, int>> prime_factorization;
	for (pair<int, int> primes : factors) {
		if (primes.second % k > 0) {
			prime_factorization.emplace_back(primes.first, primes.second % k);
		}
	}
	return prime_factorization;
}

vector<pair<int, int>> find_factor_inverse(vector<pair<int, int>> original) {
	int prime_num = original.size();
	vector<pair<int, int>> inverse(prime_num);
	for (int i = 0; i < prime_num; i++) {
		inverse[i].first = original[i].first;
		inverse[i].second = k - original[i].second;
	}
	return inverse;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    map<vector<pair<int, int>>, int> freq;
    for (int i = 0; i < n; i++) {
		freq[factor(arr[i])]++;
    }
	ll num_of_pairs = 0;
	for (int i = 0; i < n; i++) {
		if (factor(arr[i]) == find_factor_inverse(factor(arr[i]))) {
			num_of_pairs += (freq[factor(arr[i])] - 1);
		} else {
			num_of_pairs +=
			    freq[find_factor_inverse(factor(arr[i]))];
		}
	}
	cout << num_of_pairs / 2 << endl;
    return 0;
}