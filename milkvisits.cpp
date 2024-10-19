//
// Created by innav_z3e3dq9 on 8/9/2024.
//

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int component[100001];
bool visited[100001];
string breeds;
int current_component;

void dfs(int node) {
    visited[node] = true;
    component[node] = current_component;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor] && breeds[neighbor - 1] == breeds[node - 1]) {
            dfs(neighbor);
        }
    }
}

int main() {
    ifstream fin("milkvisits.in");
    ofstream fout("milkvisits.out");
    int N, M;
    fin >> N >> M;
    fin >> breeds;
    for (int i = 0; i < N - 1; i++) {
        int X, Y;
        fin >> X >> Y;
        adj[X].push_back(Y);
        adj[Y].push_back(X);
    }
    memset(visited, false, sizeof(visited));
    current_component = 0;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            current_component++;
            dfs(i);
        }
    }
    string result = "";
    for (int i = 0; i < M; i++) {
        int A, B;
        char C;
        fin >> A >> B >> C;
        if (component[A] == component[B] && breeds[A - 1] == C) {
            result += '1';
        } else if (component[A] != component[B]) {
            result += '1';
        } else {
            result += '0';
        }
    }
    fout << result << endl;
    fin.close();
    fout.close();
    return 0;
}