//
// Created by innav_z3e3dq9 on 6/5/2024.
//

#include <cstdio>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Shop {
    int amount, cost;
};

bool shop_comp(Shop a, Shop b) {return b.cost<a.cost;}

int main() {
    freopen("rental.in", "r", stdin);
    cout << "asdf";
    int n, m, r;
    cin >> n >> m >> r;
    vector<int> cows;
    for (int i = 0; i<n; i++) {
        int temp;
        cin >> temp;
        cows.push_back(temp);
    }
    sort(cows.begin(), cows.end());
    vector<Shop> shops;
    for (int i = 0; i<m; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        shops.push_back({temp1, temp2});
    }
    sort(shops.begin(), shops.end(), shop_comp);
    vector<int> rent;
    for (int i = 0; i<r; i++) {
        int temp;
        cin >> temp;
        rent.push_back(temp);
    }
    sort(rent.begin(), rent.end(), greater<>());
    rent.push_back(0);
    long long total = 0;
    int curr_shop = 0;
    int curr_renter = 0;
    for (int i = 0; i<n; i++) {
        long long shop_money = 0;
        int milk = cows[i];
        int shop_temp = curr_shop;
        if (shops[shops.size()-1].amount != 0) {
            while (milk > 0) {
                if (milk > shops[shop_temp].amount) {
                    shop_money += shops[shop_temp].amount * shops[shop_temp].cost;
                    milk -= shops[shop_temp].amount;
                    if (shop_temp + 1 == shops.size()) {
                        break;
                    } else {
                        shop_temp++;
                    }
                } else {
                    shop_money += milk * shops[shop_temp].cost;
                    milk = 0;
                }
            }
        } else {shop_money = 0;}
        cout << (shop_money > rent[curr_renter]) << "decision" << endl;
        cout << shop_money << "shop" << endl;
        cout << rent[curr_renter] << "rent" << endl;
        if (shop_money > rent[curr_renter]) {
            total += shop_money;
            milk = cows[i];
            while (milk > 0) {
                if (milk > shops[curr_shop].amount) {
                    shops[curr_shop].amount = 0;
                    milk -= shops[curr_shop].amount;
                    if (curr_shop+1 == shops.size()) {
                        break;
                    } else {
                        curr_shop++;
                    }
                } else {
                    shops[curr_shop].amount -= milk;
                    milk = 0;
                }
            }
        } else {
            total += rent[curr_renter];
            if (rent[curr_renter] != 0) {
                curr_renter++;
            }
        }
        cout << endl;
    }
    freopen("rental.out", "w", stdout);
    cout << total << endl;
    return 0;
}