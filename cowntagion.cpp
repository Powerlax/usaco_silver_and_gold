//
// Created by innav_z3e3dq9 on 8/25/2024.
//

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> cows_infected;
int days = 0;

void dfs(int node) {
    int count = 1;
    for (auto i : adj[node]) {
        if (!cows_infected[i]) {
            count++;
        }
    }
    int now = cows_infected[node];
    while (now < count) {
        now *= 2;
        days++;
    }
    int sent = 0;
    for (auto i : adj[node]) {
        if (!cows_infected[i]) {
            cows_infected[i] = 1;
            sent++;
            dfs(i);
        }
    }
    days += sent;
    cows_infected[node] = now-sent;
}

int main() {
    int n;
    cin >> n;
    adj = vector<vector<int>>(n);
    cows_infected = vector(n, 0);
    cows_infected[0] = 1;
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0);
    cout << days << endl;
    return 0;
}