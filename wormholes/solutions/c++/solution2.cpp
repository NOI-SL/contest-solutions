/**
 * contest	NOI-2020 Final
 * problem	wormholes
 * author	pasinducw
*/

#include <bits/stdc++.h>

#define rep(a, b) for(int a=0;a<b;a++)
using namespace std;

const int INF = 1e9 + 7;

int dijkstra(const int N, const vector<vector<pair<int, int>>> &E, const int S, const int D) {
    vector<int> dist(N, INF);
    vector<bool> processed(N, false);
    priority_queue<pair<int, int>> q;
    dist[S] = 0;
    q.push({0, S});

    while (!q.empty()) {
        int a = q.top().second;
        q.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (auto u: E[a]) {
            int b = u.first, w = u.second;
            if (dist[a] + w < dist[b]) {
                dist[b] = dist[a] + w;
                q.push({-dist[b], b});
            }
        }
    }

    return dist[D] == INF ? -1 : dist[D];
}

int main() {
    int N, M, W;
    cin >> N >> M >> W;

    vector<vector<pair<int, int>>> E(N);
    vector<int> Wh(W);
    vector<pair<int, int>> WhD(W);

    rep(i, M) {
        int u, v, w;
        cin >> u >> v >> w;
        E[u].push_back({v, w});
        E[v].push_back({u, w});
    }

    rep(i, W) {
        int u, v1, v2;
        cin >> u >> v1 >> v2;
        Wh[i] = u;
        WhD[i].first = v1;
        WhD[i].second = v2;
    }

    int result = -1;
    rep(i, (1 << W)) {
        vector<vector<pair<int, int>>> E2 = E;
        rep(j, W) {
            const int &wormhole = Wh[j];
            E2[wormhole].clear();
            if ((1 << j) & i) {
                E2[wormhole].push_back({WhD[j].first, 0});
            } else {
                E2[wormhole].push_back({WhD[j].second, 0});
            }
        }
        int dist = dijkstra(N, E2, 0, 1);
        if (dist == -1) {
            cout << -1 << endl;
            return 0;
        }
        result = max(result, dist);
    }
    cout << result << endl;
    return 0;
}
