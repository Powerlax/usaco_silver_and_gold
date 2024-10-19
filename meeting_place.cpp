#include <bits/stdc++.h>
using namespace std;

const double MAX_ERROR = 10e-7;
vector<double> locations;
vector<double> speeds;
double min_ans = (double)INT_MAX;
double curr_min_time;
bool left_has_max = false;
bool right_has_max = false;

double get_time(double loc) {
    double max_time = 0;
    for (int i = 0; i < locations.size(); i++) {
        if (locations[i] == loc) { continue; }
        double i_time = abs(locations[i] - loc) / speeds[i];
        if (i_time > max_time) {
            left_has_max = false;
            right_has_max = false;
            if (locations[i] > loc) {
                right_has_max = true;
            } else {
                left_has_max = true;
            }
            max_time = i_time;
        } else if (i_time == max_time) {
            if (locations[i] > loc) {
                right_has_max = true;
            } else {
                left_has_max = true;
            }
        }
    }
    return max_time;
}

int main() {
    int n;
    cin >> n;
    locations.resize(n);
    speeds.resize(n);
    double low = 0;
    double high = 0;
    double mid;
    for (int i = 0; i < n; i++) {
        cin >> locations[i];
        high = max(high, locations[i]);
    }
    for (int i = 0; i < n; i++) { cin >> speeds[i]; }
    while (high - low > MAX_ERROR) {
        mid = (high + low) / 2;
        curr_min_time = get_time(mid);
        min_ans = min(min_ans, curr_min_time);
        if (left_has_max && right_has_max) {
            break;
        } else if (left_has_max) {
            high = mid;
        } else {
            low = mid;
        }
    }
    cout << fixed << min_ans << endl;
}