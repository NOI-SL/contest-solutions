// Copyright 2019 National Olympiad in Informatics - Sri Lanka
// Author: vpj

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 10100;

int N, M;

int rect[MAXN][4];

bool in_tree[MAXN];
int to_tree[MAXN];

int segment_distance(int x1, int y11, int y12, int x2, int y21, int y22) {
    if (y21 < y11) {
        swap(y21, y11);
        swap(y22, y12);
    }

    int d = abs(x1 - x2) - 1;
    if (y12 < y21) {
        return d + y21 - y12;
    } else {
        return d;
    }
}

int distance(int i, int j) {
    int min_dis = M * 10;
    for (int dir = 0; dir < 2; ++dir) {
        for (int side_i = 0; side_i < 2; ++side_i) {
            for (int side_j = 0; side_j < 2; ++side_j) {
                int d = segment_distance(rect[i][2 * side_i + dir], rect[i][1 - dir], rect[i][3 - dir],
                                         rect[j][2 * side_j + dir], rect[j][1 - dir], rect[j][3 - dir]);
                min_dis = min(min_dis, d);
            }
        }
    }

    return min_dis;
}

int mst() {
    const int inf = M * 10;
    int cost = 0;

    for (int i = 0; i < N; ++i) {
        to_tree[i] = inf;
    }
    to_tree[0] = 0;

    for (int k = 0; k < N; ++k) {
        int n = -1, min_add = inf;
        for (int i = 0; i < N; ++i) {
            if (!in_tree[i] && min_add > to_tree[i]) {
                min_add = to_tree[i];
                n = i;
            }
        }

        in_tree[n] = true;
        cost += min_add;

        for (int i = 0; i < N; ++i) {
            int d = distance(n, i);
            to_tree[i] = min(d, to_tree[i]);
        }
    }

    return cost;
}

int main() {
    cin >> M >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> rect[i][j];
        }
    }

    cout << mst() << endl;

    return 0;
}
