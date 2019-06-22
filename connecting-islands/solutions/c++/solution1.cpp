// Copyright 2019 National Olympiad in Informatics - Sri Lanka
// Author: chethiya

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Segment {
    int x, y1, y2;

    Segment(int x, int y1, int y2) : x(x), y1(y1), y2(y2) {}

    int GetDistance(const Segment &other) const {
        int distance = abs(x - other.x) - 1; // -1 will be componsated below
        if (y2 < other.y1 || other.y2 < y1) {
            if (y2 < other.y1) {
                distance += other.y1 - y2;
            } else {
                distance += y1 - other.y2;
            }
        }
        return distance;
    }
};

struct Rect {
    int x1, y1, x2, y2;

    vector <Segment> GetSegments(int dim) const {
        if (dim == 0) {
            return vector < Segment > {Segment(x1, y1, y2), Segment(x2, y1, y2)};
        } else {
            return vector < Segment > {Segment(y1, x1, x2), Segment(y2, x1, x2)};
        }
    }

    int GetDistance(const Rect &other) const {
        vector <vector<Segment>> thisSegments{
                GetSegments(0), GetSegments(1) // boundary line segments of two dimensions
        };
        vector <vector<Segment>> otherSegments{
                other.GetSegments(0), other.GetSegments(1)
        };

        int result = INT_MAX;
        for (int dim = 0; dim < 2; ++dim) { // do this for both dimensions
            for (int i = 0; i < 2; ++i) { // 2 segments of this rectange
                for (int j = 0; j < 2; ++j) { // 2 segments of other rectable
                    result = min(result, thisSegments[dim][i].GetDistance(otherSegments[dim][j]));
                }
            }
        }
        return result;
    }
};

int main() {
    int n;
    cin >> n >> n;
    vector <Rect> rectangles;
    for (int i = 0; i < n; ++i) {
        Rect t;
        cin >> t.x1 >> t.y1 >> t.x2 >> t.y2;
        rectangles.push_back(t);
    }

    vector<bool> visited(n, false);
    vector<int> distance(n, INT_MAX);
    distance[0] = 0;
    int result = 0;

    // Running MST
    for (int i = 0; i < n; ++i) {
        // Find the best island to pick
        int best = INT_MAX;
        int bestIndex;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && distance[j] < best) {
                best = distance[j];
                bestIndex = j;
            }
        }
        result += best;
        visited[bestIndex] = true;

        // Visit all neighbour from the picked best rectangle
        for (int j = 0; j < n; ++j) {
            if (visited[j]) {
                continue;
            }
            // Shortest distance between two rectangles
            int d = rectangles[bestIndex].GetDistance(rectangles[j]);
            distance[j] = min(distance[j], d);
        }
    }

    cout << result << endl;
    return 0;
}