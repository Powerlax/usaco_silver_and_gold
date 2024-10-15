//
// Created by innav_z3e3dq9 on 6/18/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> forest(n);
    for (int i = 0; i<n; i++) {
        string temp;
        getline(cin, temp);
        for (int j = 0; j<n; j++) {
            int idk = temp[j]=='*' ? 1 : 0;
            forest[i].push_back(idk);
        }
    }
    cout << "hi";
    vector<vector<int>> pre(n+1);
    for (int i = 1; i<=n; i++) {
        pre[i].push_back(0);
        for (int j = 1; j<=n; j++) {
            pre[i].push_back(pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+forest[i-1][j-1]);
        }
    }
    for (int i = 0; i<q; i++) {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        long long ans = pre[x2][y2] - pre[x1-1][y2] - pre[x2][y1-1] + pre[x1-1][y1-1];
        cout << ans << endl;
    }
    return 0;
}