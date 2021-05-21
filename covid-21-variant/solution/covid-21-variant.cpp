#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

#define F first
#define S second

using namespace std;

#define MAX_N 250000
#define MAX_P 100100

int D1, D2, D3, D4, N, P;

bool is_old[MAX_P], can_transmit[MAX_N];

// edges are stored as a vector<pair<DISTANCE, pair<PERSON_1,PERSON_2>>>
vector<pair<int, pair<int, int>>> edges;

// here we are using the Kruskal's algorithm for MST
// refer https://cp-algorithms.com/graph/mst_kruskal.html for further
// undestanding
int getMSTValue() {
    // treeId of each node
    int tree_id[P];
    // forest
    vector<vector<int>> forest;
    // at start each node is s single tree in the forenst
    for (int i = 0; i < P; i++) {
        tree_id[i] = i;
        forest.push_back(vector<int>());
        forest[i].push_back(i);
    }
    // value of the MST
    int distance = 0;

    for (int i = 0; i < N; i++) {
        int a = edges[i].S.F, b = edges[i].S.S, c = edges[i].F;
        // if the edge can not transmit or both nodes are in the same tree,
        // continue to next iteration
        if (can_transmit[i] == false || tree_id[a] == tree_id[b]) continue;

        // get tree ids of the two nodes
        int x = tree_id[a], y = tree_id[b];
        // add current value edge to the MST
        distance += c;

        // add tree of node b to tree of node a
        for (int j = forest[y].size() - 1; j >= 0; j--) {
            tree_id[forest[y][j]] = x;
            forest[x].push_back(forest[y][j]);
        }
        // clear and remove tree of node b
        forest[y].clear();
    }

    // if every node is not in the same tree
    // MST does not contain every Node thus MST does not exist
    for (int i = 0; i < P; i++)
        if (tree_id[i] != tree_id[0]) return -1;

    return distance;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        // Take Input
        cin >> D1 >> D2 >> D3 >> D4 >> P >> N;

        // process young old persons and update is_old array
        string young_old;
        for (int i = 0; i < P; i++) {
            cin >> young_old;
            is_old[i] = young_old == "OLD";
        }

        // create the edges vector for each test case
        edges.clear();
        // process interactions (edges)
        for (int i = 0; i < N; i++) {
            int P0, P1, Dj;
            cin >> P0 >> P1 >> Dj;
            edges.push_back(make_pair(Dj, make_pair(P0, P1)));
        }
        // sort the edges so we get minimum edeges first
        // required for finding MST
        sort(edges.begin(), edges.end());

        bool COVID_19 = true, COVID_21 = true;

        // transmittable edges for COVID 19
        for (int i = 0; i < N; i++) {
            int c = edges[i].F;
            can_transmit[i] = false;
            // can_transmit only if distance is less than D1
            if (c <= D1) can_transmit[i] = true;
        }

        int distance = getMSTValue();
        // -1 means that the MST does not contain all the Nodes
        // in this case some of the persons in the room is not infected
        if (distance == -1) COVID_19 = false;

        // transmittable edges for COVID 21
        for (int i = 0; i < N; i++) {
            int a = edges[i].S.F, b = edges[i].S.S, c = edges[i].F;
            can_transmit[i] = false;
            if (is_old[a] || is_old[b]) {
                // if any of the persons are old
                // virus can jump D2 distense
                if (c <= D2) can_transmit[i] = true;
            } else {
                // othewise (between young people) it will jump D3 distance
                if (c <= D3) can_transmit[i] = true;
            }
        }

        distance = getMSTValue();
        // in the case either not all persons are in the mst
        //              OR
        // value of the mst is more than D4
        //  COVID 21 is not infected to all the people
        if (distance == -1 || distance > D4) COVID_21 = false;

        // print output accordingly
        cout << (COVID_19 == true ? "YES" : "NO") << " "
             << (COVID_21 == true ? "YES" : "NO") << endl;
    };
    return 0;
}
