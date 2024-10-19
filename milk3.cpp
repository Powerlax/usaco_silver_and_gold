/*
ID: raovish1
        TASK: test
        LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

bool visited[25][25][25];
bool possible[25];
int a_limit, b_limit, c_limit;

void dfs(int a, int b, int c) {
    if (visited[a][b][c]) {
        return;
    }
    visited[a][b][c] = true;
    if (a == 0) {
        possible[c] = true;
    }
    if (a != 0) {
        if (b_limit >= b+a) {
            dfs(0, b+a, c);
        } else {
            dfs(a-(b_limit-b), b_limit, c);
        }
        if (c_limit >= c+a) {
            dfs(0, b, c+a);
        } else {
            dfs(a-(c_limit-c), b, c_limit);
        }
    }
    if (b != 0) {
        if (a_limit >= b+a) {
            dfs(a+b, 0, c);
        } else {
            dfs(a_limit, b-(a_limit-a), c);
        }
        if (c_limit >= b+c) {
            dfs(a, 0, b+c);
        } else {
            dfs(a, b-(c_limit-c), c_limit);
        }
    }
    if (c!=0) {
        if (a_limit >= c+a) {
            dfs(a+c, b, 0);
        } else {
            dfs(a_limit, b, c-(a_limit-a));
        }
        if (b_limit >= b+c) {
            dfs(a, b+c, 0);
        } else {
            dfs(a, b_limit, c-(b_limit-b));
        }
    }
}

int main() {
    //freopen("milk3.in", "r", stdin);
    //freopen("milk3.out", "w", stdout);
    cin >> a_limit >> b_limit >> c_limit;
    dfs(0,0,c_limit);
    for (int i = 0, space_needed = 0; i<25; i++) {
        if (possible[i]) {
            cout << i;
            if (space_needed) {
                cout << " ";
            } else {
                space_needed = 1;
            }
        }
    }
}