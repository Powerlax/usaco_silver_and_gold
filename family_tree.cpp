//
// Created by innav_z3e3dq9 on 8/9/2024.
//

#include <fstream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using Relation = std::pair<string, string>;

// finds the mother of given child among those pairs (returns null if no mother)
string mother(const string &child, const vector<Relation> &relations) {
    for (const Relation &r : relations) {
        if (r.second == child) { return r.first; }
    }
    return "";
}

// returns the distance between start and end (-1 if no relation)
int ancestor_dist(
        const string &start,
        string end,  // we're going to reassign this variable so no reference
        const vector<Relation> &relations) {
    int dist = 0;
    while (end != "") {
        if (end == start) { return dist; }
        dist++;
        end = mother(end, relations);
    }
    return -1;
}

int main() {
    std::ifstream read("family.in");
    int rel_num;
    string cow_x;
    string cow_y;
    read >> rel_num >> cow_x >> cow_y;
    vector<Relation> relations(rel_num);
    for (int r = 0; r < rel_num; r++) {
        read >> relations[r].first >> relations[r].second;
    }

    // minimum distance between the shared ancestor and X and Y
    int min_x_dist = 0;
    int min_y_dist = 0;
    string common_ancestor = cow_x;
    // try to find the common ancestor of X and Y (or if there isn't one)
    while (!common_ancestor.empty()) {
        if (ancestor_dist(common_ancestor, cow_y, relations) != -1) {
            min_y_dist = ancestor_dist(common_ancestor, cow_y, relations);
            break;
        }
        common_ancestor = mother(common_ancestor, relations);
        min_x_dist++;
        // written << common_ancestor << '\n';
    }

    std::ofstream written("family.out");
    // if X and Y don't have common ancestors, they aren't related
    if (common_ancestor.empty()) {
        written << "NOT RELATED\n";
    }
        // if both distances are greater than one they're cousins
    else if (min_x_dist > 1 && min_y_dist > 1) {
        written << "COUSINS\n";
    }
        // both distances of 1 means they're siblings
    else if (min_x_dist == 1 && min_y_dist == 1) {
        written << "SIBLINGS\n";
    }
        // if one itself is the ancestor then it's a (great-...) mother relationship
    else if (min_x_dist == 0 || min_y_dist == 0) {
        bool x_is_ancestor = min_x_dist == 0;
        int ancestor_dist = x_is_ancestor ? min_y_dist : min_x_dist;
        written << (x_is_ancestor ? cow_x : cow_y) << " is the ";
        for (int i = 0; i < ancestor_dist - 2; i++) { written << "great-"; }
        if (ancestor_dist > 1) { written << "grand-"; }
        written << "mother of " << (x_is_ancestor ? cow_y : cow_x) << '\n';
    }
        // otherwise, there's a (great-great-...) aunt relationship
    else {
        bool x_is_aunt = min_x_dist == 1;
        written << (x_is_aunt ? cow_x : cow_y) << " is the ";
        for (int i = 0; i < (x_is_aunt ? min_y_dist : min_x_dist) - 2; i++) {
            written << "great-";
        }
        written << "aunt of " << (x_is_aunt ? cow_y : cow_x) << '\n';
    }
}