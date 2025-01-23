//
// Created by innav_z3e3dq9 on 1/20/2025.
//

#include <bits/stdc++.h>
using namespace std;

using Point = pair<int, int>;
using Fence = pair<Point, Point>;

int getDist(const Point &a, const Point &b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

Point getOther(const Fence &fence, const Point &post) {
    return (post == fence.first) ? fence.second : fence.first;
}

int main() {
    int N, P;
    cin >> N >> P;
    vector<Point> posts(P);
    for (int i = 0; i < P; i++) {
        cin >> posts[i].first >> posts[i].second;
    }
    vector<pair<Point, Point>> start_ends(N);
    vector<Point> query_poses;
    for (int i = 0; i < N; i++) {
        Point start, end;
        cin >> start.first >> start.second >> end.first >> end.second;
        start_ends[i] = {start, end};
        query_poses.push_back(start);
        query_poses.push_back(end);
    }
    vector<Point> orig_posts = posts;
    sort(posts.begin(), posts.end());
    sort(query_poses.begin(), query_poses.end());
    map<int, vector<Point>> posts_at_x, posts_at_y, queries_at_x, queries_at_y;
    for (const auto& post : posts) {
        posts_at_x[post.first].push_back(post);
        posts_at_y[post.second].push_back(post);
    }
    for (const auto& query : query_poses) {
        queries_at_x[query.first].push_back(query);
        queries_at_y[query.second].push_back(query);
    }
    map<Point, Fence> vert_fence, horz_fence;
    map<Point, Fence> on_fence;
    for (auto& [x, x_posts] : posts_at_x) {
        for (size_t i = 0; i < x_posts.size(); i += 2) {
            vert_fence[x_posts[i]] = vert_fence[x_posts[i + 1]] = {x_posts[i], x_posts[i + 1]};
        }
        auto& queries = queries_at_x[x];
        long long post_index = 0;
        for (const auto& query : queries) {
            while (post_index + 2 < x_posts.size() && x_posts[post_index + 1].second < query.second) {
                post_index += 2;
            }
            if (x_posts[post_index].second <= query.second && query.second <= x_posts[post_index + 1].second) {
                on_fence[query] = {x_posts[post_index], x_posts[post_index + 1]};
            }
        }
    }
    for (auto& [y, y_posts] : posts_at_y) {
        for (size_t i = 0; i < y_posts.size(); i += 2) {
            horz_fence[y_posts[i]] = horz_fence[y_posts[i + 1]] = {y_posts[i], y_posts[i + 1]};
        }
        auto &queries = queries_at_y[y];
        size_t post_index = 0;
        for (const auto &query : queries) {
            while (post_index + 2 < y_posts.size() && y_posts[post_index + 1].first < query.first) {
                post_index += 2;
            }
            if (y_posts[post_index].first <= query.first && query.first <= y_posts[post_index + 1].first) {
                on_fence[query] = {y_posts[post_index], y_posts[post_index + 1]};
            }
        }
    }
    vector ordered_posts = {posts.front()};
    for (size_t i = 1; i < P; ++i) {
        if (i % 2 == 1) {
            ordered_posts.push_back(getOther(horz_fence[ordered_posts.back()], ordered_posts.back()));
        } else {
            ordered_posts.push_back(getOther(vert_fence[ordered_posts.back()], ordered_posts.back()));
        }
    }
    map<Fence, int> directed_fence_to_ind;
    map<Point, int> post_to_ind;
    for (int i = 0; i < P; i++) {
        directed_fence_to_ind[{ordered_posts[i], ordered_posts[(i + 1) % P]}] = i;
        post_to_ind[ordered_posts[i]] = i;
    }
    vector dist_to(P, 0);
    int tot_dist = 0;
    for (long long i = 0; i < P; i++) {
        dist_to[i] = tot_dist;
        tot_dist += getDist(ordered_posts[i], ordered_posts[(i + 1) % P]);
    }
    auto get_dist_along = [&](const Point& query) {
        const auto &[fst, snd] = on_fence[query];
        const int ind = post_to_ind[fst];
        return dist_to[ind] + getDist(fst, query);
    };
    vector ans(P, 0);
    for (const auto &[start, end] : start_ends) {
        auto start_dist = get_dist_along(start);
        auto end_dist = get_dist_along(end);
        if (start_dist > end_dist) swap(start_dist, end_dist);
        if (end_dist - start_dist > tot_dist - (end_dist - start_dist)) {
            swap(start_dist, end_dist);
        }
        int start_ind = post_to_ind[start];
        int end_ind = post_to_ind[end];
        ans[start_ind]++;
        if (end_ind + 1 < P) ans[end_ind + 1]--;
        if (start_ind > end_ind) ans[0]++;
    }
    for (size_t i = 1; i < P; ++i) {
        ans[i] += ans[i - 1];
    }
    for (const auto& post : orig_posts) {
        cout << ans[post_to_ind[post]] << endl;
    }
    return 0;
}