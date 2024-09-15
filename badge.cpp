//
// Created by innav_z3e3dq9 on 8/12/2024.
//

#include <bits/stdc++.h>
using namespace std;

map<int, int> blame;

int succ(int node) {
    return blame[node];
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i<n; i++) {
        int temp;
        cin >> temp;
        temp--;
        blame[i] = temp;
    }
    for (int i = 0; i<n; i++) {
        int a = succ(i);;
        int b = succ(succ(i));
        while (a != b) {
            a = succ(a);
            b = succ(succ(b));
        }
        a = i;
        while (a != b) {
            a = succ(a);
            b = succ(b);
        }
        cout << a+1 << " ";
    }
    return 0;
}