//
// Created by innav_z3e3dq9 on 12/5/2024.
//

//Idea: This is a basic LCA problem.
//You flatten out the tree using Euler Tour in order to be able to perform tree queries on it.
//RMQ using sparse table on the heights(RMQ[0])
//Index of the answer is the minimum between any appearance of a, b, otherwise, Query(a, b)
//As a matter of fact any appearance is fine but the first one minimizes the size of the range
//For proof read: https://cp-algorithms.com/graph/lca.html

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

int n, q;
vi adj[MAXN];
pi RMQ[20][2*MAXN+2]; //{Minimum, index of minimum}
int *eulerTour, *start;
int timer = 0;

void dfs(int u, int e = -1, int h = 1) { //e: parent, h: height
    start[u] = timer;
    RMQ[0][timer] = {h, timer};
    eulerTour[timer++] = u;
    for(int v : adj[u]) {
        if(v != e) {
            dfs(v, u, h+1);
            RMQ[0][timer] = {h, timer};
            eulerTour[timer++] = u;
        }
    }
}

void sparseTable() {
    for(int i = 1; i <= log2(2*n-1)+1; ++i) {
        for(int j = 0; j + (1 << i) <= 2*n-1; ++j) {
            if (RMQ[i-1][j].fi < RMQ[i-1][j + (1 << (i - 1))].fi) {
                RMQ[i][j] = RMQ[i-1][j];
            }
            else {
                RMQ[i][j] = RMQ[i-1][j + (1 << (i - 1))];
            }
        }
    }
}

int Query(int l, const int r) {
    int i = static_cast<int>(log2(r - l + 1));
    if (RMQ[i][l].fi < RMQ[i][r - (1 << i) + 1].fi) {
        return RMQ[i][l].se;
    }
    return RMQ[i][r - (1 << i) + 1].se;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> q;
    start = new int[2*n+1];
    eulerTour = new int[2*n+1];
    for(int u = 2; u <= n; u++) {
        int v;
        cin >> v;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1);
    sparseTable();
    while(q--) {
        int a, b;
        si(a); si(b);
        a = start[a];
        b = start[b];
        if(a > b) std::swap(a, b);
        printf("%d\n", eulerTour[Query(a, b)]);
    }
    delete[] start;
    delete[] eulerTour;
    return 0;
}