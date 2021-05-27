#include <bits/stdc++.h>

using namespace std;

map<char, long long> changeCost;
map<char, long long> removeCost;
map<pair<char, char>, long long> rewardCombinations;
string A, B;
long long dp[110][110];
const long long inf = LLONG_MAX;
const char SUITS[] = {'S', 'H', 'D', 'C'};
long long bestCombination = -inf;

void readInput() {
    cin >> A >> B;

    char suit, s1, s2;
    long long a, r;
    for (int i = 0; i < 4; ++i) {
        cin >> suit >> a >> r;
        changeCost[suit] = a;
        removeCost[suit] = r;
    }

    for (int i = 0; i < 10; ++i) {
        cin >> s1 >> s2 >> r;
        rewardCombinations[make_pair(s1, s2)] = r;
        rewardCombinations[make_pair(s2, s1)] = r;
        bestCombination = max(bestCombination, r);
    }
}

int changeAndMatch(char suit, char toSuit) {
    long long mn = inf;
    for (int i = 0; i < 4; ++i) {
        mn = min(mn, -rewardCombinations[make_pair(SUITS[i], toSuit)] + changeCost[suit]);
    }

    return mn;
}

int main() {
    readInput();

    for (int i = 0; i <= A.size(); ++i) {
        for (int j = 0; j <= B.size(); ++j) {
            dp[i][j] = inf;
        }
    }

    dp[A.size()][B.size()] = 0;

    for (int i = (int) A.size(); i >= 0; --i) {
        for (int j = (int) B.size(); j >= 0; --j) {
            if (i < A.size()) {
                dp[i][j] = min(dp[i][j], dp[i + 1][j] + removeCost[A[i]]);
            }
            if (j < B.size()) {
                dp[i][j] = min(dp[i][j], dp[i][j + 1] + removeCost[B[j]]);

            }
            if (i < A.size() && j < B.size()) {
                dp[i][j] = min(dp[i][j], dp[i + 1][j + 1] - rewardCombinations[make_pair(A[i], B[j])]);
                dp[i][j] = min(dp[i][j], dp[i + 1][j + 1] - bestCombination + changeCost[A[i]] + changeCost[B[j]]);
                dp[i][j] = min(dp[i][j], dp[i + 1][j + 1] + changeAndMatch(A[i], B[j]));
                dp[i][j] = min(dp[i][j], dp[i + 1][j + 1] + changeAndMatch(B[j], A[i]));
            }
        }
    }

    cout << -dp[0][0] << endl;

    return 0;
}
