#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> arr;
    for (int i = 0; i<n; i++) {
        long long temp;
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
//    for (auto element : arr) {
//        cout << element << " ";
//    }
    long long ans = INT_MIN;
    long long tuition = INT_MIN;
    for (int i = 0; i<n; i++) {
        if (arr[i]*(n-i) > ans) {
            ans = arr[i]*(n-i);
            tuition = arr[i];
        }
    }
    cout << to_string(ans) + " " + to_string(tuition);
    return 0;
}
