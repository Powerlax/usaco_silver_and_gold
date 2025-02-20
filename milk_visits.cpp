//
// Created by innav_z3e3dq9 on 12/8/2024.
//

#include <bits/stdc++.h>
using namespace std;

struct LCA{
    int M;
    vector<int> etour;
    int ofst[100000];
    int depth[100000];
    int st[20][300001];
    int lg2[300001];

    int idminf(int a, int b){
        return (depth[a] < depth[b] ? a : b);
    }

    void dfs(vector<int> (&graph)[100000], int id, int par, int d){
        depth[id] = d;
        ofst[id] = etour.size();
        etour.push_back(id);
        for(int i : graph[id]){
            if(i == par) continue;
            dfs(graph, i, id, d+1);
            etour.push_back(id);
        }
    }

    void build(){
        M = etour.size();
        lg2[1] = 0;
        for(int i = 2; i <= M; i++){
            lg2[i] = lg2[i/2] + 1;
        }
        copy(etour.begin(), etour.end(), st[0]);
        for(int i = 1; i < 20; i++){
            for(int j = 0; j + (1<<i) - 1 < M; j++){
                st[i][j] = idminf(st[i-1][j], st[i-1][j + (1<<(i-1))]);
            }
        }
    }

    int lca(int u, int v){
        int l = ofst[u], r = ofst[v];
        if(l > r) swap(l, r);
        int p2 = lg2[r-l+1];
        return idminf(st[p2][l], st[p2][r-(1<<p2)+1]);
    }
} lca;

int n, m;
int t[100000];
vector<int> graph[100000];
vector<int> fwd[100000], bck[100000];
int o1[100000];
int cnttrav = 0;

void dfs(int id, int par){
    o1[id] = cnttrav;
    fwd[t[id]].push_back(cnttrav++);
    for(int i : graph[id]){
        if(i == par) continue;
        dfs(i, id);
    }
    bck[t[id]].push_back(cnttrav++);
}

int qrange(vector<int> &v, int a, int b){
    return upper_bound(v.begin(), v.end(), b) - lower_bound(v.begin(), v.end(), a);
}

signed main(){
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> t[i];
        t[i]--;
    }
    for(int i = 0; i < n-1; i++){
        int x, y;
        cin >> x >> y;
        graph[x-1].push_back(y-1);
        graph[y-1].push_back(x-1);
    }
    lca.dfs(graph, 0, 0, 0);
    lca.build();
    dfs(0, 0);
    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        a--; b--; c--;
        int clca = lca.lca(a, b);
        int l = o1[clca];
        int r1 = o1[a], r2 = o1[b];
        int p1 = qrange(fwd[c], l, r1), m1 = qrange(bck[c], l, r1);
        int p2 = qrange(fwd[c], l, r2), m2 = qrange(bck[c], l, r2);
        int s1 = p1 - m1, s2 = p2 - m2;
        cout << (s1 + s2 > 0 ? 1 : 0);
    }
    cout << endl;
}