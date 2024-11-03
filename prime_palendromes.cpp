/*
 ID: raovish1
 LANG: C++11
 TASK: pprime
 */

#include <bits/stdc++.h>
using namespace std;

bool is_prime(int num) {
    if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }
    for (int i = 5; i*i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("pprime.in", "r", stdin);
    freopen("pprime.out", "w", stdout);
    int a, b;
    cin >> a >> b;
    for (int i = a; i<=b; i++) {
        if (is_prime(i)) {
            bool good = true;
            string prime_num = to_string(i);
            for (int j = 0; j<prime_num.size()/2; j++) {
                if (prime_num[j] != prime_num[prime_num.size()-j-1]) {
                    good = false;
                    break;
                }
            }
            if (good) {
                cout << prime_num << endl;
            }
        }
    }
    return 0;
}