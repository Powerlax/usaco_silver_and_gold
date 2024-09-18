#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> times(n);
    for (int i = 0; i < n; i++) {
        cin >> times[i];
    }

    int start = 0, end = 0, currentSum = 0, maxLength = 0;
    while (end < n) {
        currentSum += times[end];
        while (currentSum > t) {
            currentSum -= times[start];
            start++;
        }
        maxLength = max(maxLength, end - start + 1);
        end++;
    }

    cout << maxLength << endl;

    return 0;
}