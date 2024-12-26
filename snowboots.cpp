//
// Created by innav_z3e3dq9 on 7/14/2024.
//

#include <bits/stdc++.h>
using namespace std;

int findFirstOccurrence(const vector<int>& row, int target) {
    int low = 0, high = row.size() - 1, res = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (row[mid] == target) {
            res = mid;
            high = mid - 1; // Move left
        } else if (row[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return res;
}
int findLastOccurrence(const vector<int>& row, int target) {
    int low = 0, high = row.size() - 1, res = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (row[mid] == target) {
            res = mid;
            low = mid + 1; // Move right
        } else if (row[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return res;
}
int countOccurrences(const vector<int>& row, int target) {
    int first = findFirstOccurrence(row, target);
    if (first == -1) return 0; // Element not found
    int last = findLastOccurrence(row, target);
    return last - first + 1;
}

int main() {
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);
    int n, b;
    cin >> n >> b;
    vector<int> depths(n);
    int most = -1;
    for (int i = 0; i<n; i++) {
        cin >> depths[i];
        most = max(most, depths[i]);
    }
    for (int i = 0; i<b; i++) {
        int depth, dist;
        cin >> depth >> dist;
        if (depth >= most) {
            cout << 1 << endl;
            continue;
        }
        if (dist == n-1) {
            cout << 1 << endl;
            continue;
        }
        if (dist == 1) {
            cout << 0 << endl;
            continue;
        }

    }
    return 0;
}