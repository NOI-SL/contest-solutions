// Copyright 2019 National Olympiad in Informatics - Sri Lanka
// Author: chethiya

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

const char SUITS[4] = {'D', 'C', 'H', 'S'};
const string VALUES[13] = {
        "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"
};

pair<int, int> GetCardLocation(string card) {
    pair<int, int> result;
    for (int i = 0; i < 4; ++i) {
        if (card[0] == SUITS[i]) {
            result.first = i;
            break;
        }
    }
    card = card.substr(1);
    for (int i = 0; i < 13; ++i) {
        if (card == VALUES[i]) {
            result.second = i;
            break;
        }
    }
    return result;
}

string GetCardString(const pair<int, int> &card) {
    return SUITS[card.first] + VALUES[card.second];
}

vector <pair<int, int>>
FindBestPath(const pair<int, int> &S, const pair<int, int> &E, const vector <vector<int>> &costs) {
    vector < vector < pair < int, int >> > distance(
            4,
            vector < pair < int, int >> (13, make_pair(INT_MAX, INT_MAX))
    );
    vector < vector < pair < int, int >> > edge(
            4,
            vector < pair < int, int >> (13, make_pair(INT_MAX, INT_MAX))
    );
    vector <vector<bool>> used(4, vector<bool>(13, false));
    distance[S.first][S.second] = make_pair(costs[S.first][S.second], 1);

    while (true) {
        // Find best
        pair<int, int> bestCard;
        pair<int, int> best{INT_MAX, INT_MAX};
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 13; ++j) {
                if (!used[i][j] && best > distance[i][j]) {
                    best = distance[i][j];
                    bestCard = make_pair(i, j);
                }
            }
        }
        used[bestCard.first][bestCard.second] = true;
        if (bestCard == E) {
            break;
        }

        vector <pair<int, int>> nextCards;
        for (int i = -1; i <= 1; i += 2) {
            // suit change
            nextCards.push_back(make_pair(
                    (bestCard.first + i + 4) % 4, bestCard.second
            ));
            // value change
            nextCards.push_back(make_pair(
                    bestCard.first, (bestCard.second + i + 13) % 13
            ));
        }
        for (const auto &card: nextCards) {
            if (used[card.first][card.second]) {
                continue;
            }
            auto cost = make_pair(
                    best.first + costs[card.first][card.second],
                    best.first + 1
            );
            if (cost < distance[card.first][card.second]) {
                distance[card.first][card.second] = cost;
                edge[card.first][card.second] = bestCard;
            }
        }
    }
    auto cur = E;
    vector <pair<int, int>> result;
    while (true) {
        result.push_back(cur);
        if (distance[cur.first][cur.second].second == 1) {
            break;
        }
        cur = edge[cur.first][cur.second];
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    pair<int, int> S, E;
    vector <vector<int>> costs(4, vector<int>(13, 0));
    {
        string start, end;
        cin >> start >> end;
        S = GetCardLocation(start);
        E = GetCardLocation(end);
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 13; ++j) {
            cin >> costs[i][j];
        }
    }
    vector <pair<int, int>> path = FindBestPath(S, E, costs);
    int cost = 0;
    for (const auto &card: path) {
        cost += costs[card.first][card.second];
    }
    cout << path.size() << " " << cost << endl;
    bool first = true;
    for (const auto &card: path) {
        if (first) {
            first = false;
        } else {
            cout << " ";
        }
        cout << GetCardString(card);
    }
    cout << endl;
}