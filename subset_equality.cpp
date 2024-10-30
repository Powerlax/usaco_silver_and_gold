//
// Created by innav_z3e3dq9 on 10/26/2024.
//

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s, t;
    cin >> s >> t;
    vector<int> freqS(18);
    vector<int> freqT(18);
    for (char i : s){
        freqS[i - 'a']++;
    }
    for (char i : t){
        freqT[i - 'a']++;
    }
    vector comp(18, vector<bool>(18));
    for (char i = 'a'; i <= 'r'; i++){
        for (char j = 'a'; j <= 'r'; j++){
            string sp, tp;
            for (char q : s){
                if (q == i || q == j){
                    sp += q;
                }
            }
            for (char q : t){
                if (q==i || q==j){
                    tp += q;
                }
            }
            comp[i-'a'][j-'a'] = sp == tp;
        }
    }
    int q;
    cin >> q;
    while(q--) {
        string query;
        cin >> query;
        int sL = 0;
        int tL = 0;
        for (char c : query) {
            sL += freqS[c-'a'];
            tL += freqT[c-'a'];
        }
        if (sL != tL) {
            cout << "N";
            continue;
        }
        bool b = false;
        for (int i : query) {
            for (int j : query) {
                if (!comp[i-'a'][j-'a']) {
                    b = true;
                }
            }
        }
        if (b) {
            cout << "N";
        }else {
            cout << "Y";
        }
    }
}