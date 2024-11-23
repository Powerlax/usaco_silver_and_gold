//
// Created by innav_z3e3dq9 on 11/23/2024.
//

#include <bits/stdc++.h>
using namespace std;

vector<int> bessie, elsie;

bool compBessie(const int x, const int y) {
    return elsie[x] < elsie[y];
}

bool compElsie(const int x, const int y) {
    return bessie[x] < bessie[y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("piepie.in", "r", stdin);
    freopen("piepie.out", "w", stdout);
    int n, d;
    cin >> n >> d;
    bessie.resize(n * 2);
    elsie.resize(n * 2);
    vector dist(n * 2, -1);
    for (int i = 0; i < n * 2; i++) {
        cin >> bessie[i] >> elsie[i];
        bessie[i] = -bessie[i];
        elsie[i] = -elsie[i];
    }
    int len = 0;
    vector<int> order(n * 2);
    multiset<int, decltype(compBessie)*> bessie_pies{compBessie};
    multiset<int, decltype(compElsie)*> elsie_pies{compElsie};
    for (int i = 0; i < n; i++) {
        if (elsie[i] == 0) {
            order[len++] = i;
            dist[i] = 1;
        } else {
            bessie_pies.insert(i);
        }
        if (bessie[i + n] == 0) {
            order[len++] = i + n;
            dist[i + n] = 1;
        } else {
            elsie_pies.insert(i + n);
        }
    }
    for (int curr = 0; curr < len; curr++) {
        if (int i = order[curr]; i < n) {
            while (true) {
                auto it = elsie_pies.lower_bound(i);
                if (it == elsie_pies.end() || bessie[*it] > bessie[i] + d + 1) {
                    break;
                }
                dist[*it] = dist[i] + 1;
                order[len++] = *it;
                elsie_pies.erase(it);
            }
        } else {
            while (true) {
                auto it = bessie_pies.lower_bound(i);
                if (it == bessie_pies.end() || elsie[*it] > elsie[i] + d) {
                    break;
                }
                dist[*it] = dist[i] + 1;
                order[len++] = *it;
                bessie_pies.erase(it);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << dist[i] << endl;
    }
}