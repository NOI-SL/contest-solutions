#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int N, M, W;
int edges[5100][3];
int wormholes[100][3];
bool has_wh[110];
long long dis[110];

const long long inf = 1LL << 60;

bool bellman_reduce(int s, int e, int t) {
    if (has_wh[s]) {
        return false;
    }

    if (dis[s] > dis[e] + t) {
        dis[s] = dis[e] + t;
        return true;
    } else {
        return false;
    }
}

bool bellman() {
    bool reduced = false;

    for (int i = 0; i < M; ++i) {
        reduced |= bellman_reduce(edges[i][0], edges[i][1], edges[i][2]);
        reduced |= bellman_reduce(edges[i][1], edges[i][0], edges[i][2]);
    }

    for (int i = 0; i < W; ++i) {
        long long mx = max(dis[wormholes[i][1]], dis[wormholes[i][2]]);
        if (dis[wormholes[i][0]] > mx) {
            dis[wormholes[i][0]] = mx;
            reduced = true;
        }
    }

    return reduced;
}

int main() {
    cin >> N >> M >> W;

    for (int i = 0; i < M; ++i) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    for (int i = 0; i < W; ++i) {
        cin >> wormholes[i][0] >> wormholes[i][1] >> wormholes[i][2];
        has_wh[wormholes[i][0]] = true;
    }

    for (int i = 0; i < N; ++i) {
        dis[i] = inf;
    }

    dis[1] = 0;

    for (int i = 0; i < N; ++i) {
        bellman();
    }

    if (bellman()) {
        cout << -1 << endl;
        return 0;
    }

    if (dis[0] >= inf) {
        cout << -1 << endl;
    } else {
        cout << dis[0] << endl;
    }

    return 0;
}
