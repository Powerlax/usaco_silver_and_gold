//
// Created by innav_z3e3dq9 on 12/12/2024.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Cow {
    int weight;
    int position;
    int direction;
};

int main() {
    int N, L;
    cin >> N >> L;
    freopen("input.txt", "r", cin.get());

    vector<Cow> cows(N);
    vector<pair<int, int>> events; // {time, event type (-1 for left, +1 for right)}
    int totalWeight = 0;

    for (int i = 0; i < N; i++) {
        cin >> cows[i].weight >> cows[i].position >> cows[i].direction;
        totalWeight += cows[i].weight;
        if (cows[i].direction == -1) {
            events.push_back({cows[i].position, -1});
        } else {
            events.push_back({L - cows[i].position, 1});
        }
    }

    sort(events.begin(), events.end());

    int halfWeight = (totalWeight + 1) / 2;
    int stoppedWeight = 0;
    int T = 0;

    for (const auto& event : events) {
        stoppedWeight += event.second == -1 ? cows[event.second].weight : cows[event.second].weight;
        if (stoppedWeight >= halfWeight) {
            T = event.first;
            break;
        }
    }

    // Calculate number of meetings
    vector<pair<int, int>> positions;
    for (int i = 0; i < N; i++) {
        positions.push_back({cows[i].position, cows[i].direction});
    }

    sort(positions.begin(), positions.end());

    int meetings = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (positions[i].second == 1 && positions[j].second == -1) {
                double meetTime = (positions[j].first - positions[i].first) / 2.0;
                if (meetTime <= T) {
                    cout << "hi" << endl;
                    meetings++;
                }
            }
        }
    }

    cout << meetings << endl;

    return 0;
}
