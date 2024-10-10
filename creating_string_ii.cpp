//
// Created by innav_z3e3dq9 on 9/4/2024.
//

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;
const int MAXN = 1e6;

array<ll, MAXN + 1> fact;
array<ll, MAXN + 1> inv;

ll modpow(ll a, ll b, ll m) {
	ll prod = 1;
	while (b > 0) {
		if (b % 2 == 1) {
        	prod = (prod * a) % m;
        }
		b /= 2;
		a = (a * a) % m;
	}
	return prod;
}

int main() {
	fact[0] = inv[0] = fact[1] = inv[1] = 1;
	for (int i = 2; i <= MAXN; i++) {
		fact[i] = fact[i - 1] * i % MOD;
		inv[i] = modpow(fact[i], MOD - 2, MOD);
	}
	string s;
	cin >> s;
	vector<int> character_count(26);
	for (char i : s) {
          character_count[i - 'a']++;
    }
	ll total = fact[s.length()];
	for (int i : character_count) {
		total = total * inv[i] % MOD;
	}
	cout << total << endl;
}