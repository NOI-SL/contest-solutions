/**
 * contest	NOI-2020 Final
 * problem	game of cards
 * author	pasinducw
*/

#include <bits/stdc++.h>

#define rep(a, b) for(int a=0;a<b;a++)
using namespace std;
typedef long long ll;

string s1, s2;

ll change[26];
ll rem[26];
ll comb[26][26];
ll dp[101][101];

// N -> number of chars from s1
// M -> number of chars from s2
ll getBest(int N, int M) {
    if (N < 0 || M < 0) throw -1;

    if (dp[N][M]) return dp[N][M];

    if (N == 0 || M == 0) {
        ll cost = 0;
        rep(i, N) cost += rem[s1[i] - 'A'];
        rep(i, M) cost += rem[s2[i] - 'A'];
        dp[N][M] = -cost;
        return -cost;
    }

    ll solution = max(getBest(N, M - 1) - rem[s2[M - 1] - 'A'],
                      getBest(N - 1, M) - rem[s1[N - 1] - 'A']); // remove scenario

    char options[] = {'S', 'H', 'C', 'D'}; // change scenario
    for (auto o1: options)
        for (auto o2: options) {
            ll cost = 0;
            if (s1[N - 1] != o1) cost += change[s1[N - 1] - 'A'];
            if (s2[M - 1] != o2) cost += change[s2[M - 1] - 'A'];

            solution = max(solution, getBest(N - 1, M - 1) + comb[o1 - 'A'][o2 - 'A'] - cost);
        }
    dp[N][M] = solution;
    return solution;
}

int main() {
    cin >> s1 >> s2;

    rep(i, 4) {
        char S;
        cin >> S;
        cin >> change[S - 'A'] >> rem[S - 'A'];
    }

    rep(i, 10) {
        char u, v;
        cin >> u >> v;
        cin >> comb[u - 'A'][v - 'A'];
    }

    int N = s1.size(), M = s2.size();

    cout << getBest(N, M) << endl;
    return 0;
}
