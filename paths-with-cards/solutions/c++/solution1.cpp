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

const int inf = 1 << 30;
const int dis_offset = 1 << 6;

const int MAXN = 1000;

const int S = 4;
const int R = 13;
string suits[S] = {"D", "C", "H", "S"};
string ranks[R] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
int costs[S][R];

int parent[MAXN];
int dis[MAXN];
int vis[MAXN];

int get_card(string s) {
    int card = 0;
    for (int i = 0; i < S; ++i) {
        if (s[0] == suits[i][0]) {
            card = i * 100;
        }
    }
    for (int i = 0; i < R; ++i) {
        if (s[1] == ranks[i][0]) {
            card += i;
        }
    }

    return card;
}

string print_card(int n) {
    string card = suits[n / 100] + ranks[n % 100];

    return card;
}

void dijkstra(int from) {
    for (int i = 0; i < MAXN; ++i) {
        dis[i] = inf;
    }
    dis[from] = 0;
    int next[4];

    for (int k = 0; k < MAXN; ++k) {
        int min_dis = inf, n = -1;
        for (int i = 0; i < MAXN; ++i) {
            if (!vis[i] && min_dis > dis[i]) {
                min_dis = dis[i];
                n = i;
            }
        }
        if (n == -1) {
            break;
        }

        vis[n] = true;
        int s = n / 100;
        int r = n % 100;
        next[0] = ((s + S - 1) % S) * 100 + r;
        next[1] = ((s + 1) % S) * 100 + r;
        next[2] = s * 100 + (r + R - 1) % R;
        next[3] = s * 100 + (r + 1) % R;

        for (int i = 0; i < 4; ++i) {
            if (next[i] == 99) {
                break;
            }
            int j = next[i];
            s = j / 100;
            r = j % 100;
            // For least cost and shortest path
            if (dis[j] > min_dis + costs[s][r] * dis_offset + 1) {
                dis[j] = min_dis + costs[s][r] * dis_offset + 1;
                parent[j] = n;
            }
        }
    }
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int start = get_card(s1);
    int end = get_card(s2);

    for (int i = 0; i < S; ++i) {
        for (int j = 0; j < R; ++j) {
            cin >> costs[i][j];
        }
    }

    dijkstra(end);

    int n = start;

    vector<int> cards;
    int cost = 0;

    while (true) {
        cards.push_back(n);
        cost += costs[n / 100][n % 100];
        if (n == end) {
            break;
        }
        n = parent[n];
    }

    cout << cards.size() << " " << cost << endl;
    cout << print_card(cards[0]);
    for (int i = 1; i < (int) cards.size(); ++i) {
        cout << " " << print_card(cards[i]);
    }
    cout << endl;
}
