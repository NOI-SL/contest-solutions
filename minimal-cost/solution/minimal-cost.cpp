#include <bits/stdc++.h>

using namespace std;

int min_gcd = INT_MAX;

map<int, map<int, int>> DPS;

// Euclidean algorithm for finding GCD
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int dfs_gcd(int i, int min_gcd, vector<vector<int>>& adj, int* values,
            vector<bool> visited) {
    // DP check if the result exsists
    if (DPS[i][min_gcd]) return DPS[i][min_gcd];

    int minx = INT_MAX;
    //  for each neighbor "X" of current Vertex  :
    for (auto x : adj[i]) {
        if (visited[x]) continue;
        min_gcd = gcd(min_gcd, values[x]);
        minx = min(min_gcd, minx);
        visited[x] = true;
        minx = min(dfs_gcd(x, min_gcd, adj, values, visited), minx);
    }
    
    // store result in the map
    DPS[i][min_gcd] = minx;

    return minx;
}

int main() {
    int N, M;

    cin >> N >> M;

    int values[N];
    vector<vector<int>> adj(N);

    // Input cities
    for (int i = 0; i < N; ++i) {
        cin >> values[i];
        // find min value form cities
        min_gcd = min(values[i], min_gcd);
    }

    // create adjacency list
    for (int i = 0; i < M; ++i) {
        int S, E;
        cin >> S >> E;
        adj[S - 1].push_back(E - 1);
    }

    vector<bool> visited(N, false);

    // dfs each node
    for (int i = 0; i < N; ++i) {
        int minx = dfs_gcd(i, values[i], adj, values, visited);
        min_gcd = min(min_gcd, minx);
    }

    cout << min_gcd;

    return 0;
}
