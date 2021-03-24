#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


void proc() {

    bool showOn = false,
            shamApplied = false,
            condApplied = false,
            bathOpen = false,
            hairDried = true;
    int shamRemaining = 2, condRemaining = 2;

    int count;
    string inp;

    cin >> count >> inp;

    for (int j = 0; j < count; j++) {
        switch (inp[j]) {
            case 'G':
                bathOpen = !bathOpen;
                break;
            case 'O':
                if (bathOpen && !showOn) {
                    showOn = true;
                    hairDried = false;
                    shamApplied = false;
                    condApplied = false;
                } else {
                    cout << "N " << j << endl;
                    return;
                }
                break;
            case 'F':
                if (bathOpen && showOn) {
                    showOn = false;
                } else {
                    cout << "N " << j << endl;
                    return;
                }
                break;
            case 'S':
                if (bathOpen /*&& !condApplied*/ /*&& !shamApplied*/ /*&& !hairDried*/ && shamRemaining > 0) {
                    if (!showOn) {
                        shamApplied = true;
                    }
                    shamRemaining--;
                } else {
                    cout << "N " << j << endl;
                    return;
                }
                break;
            case 'C':
                if (bathOpen && /*!condApplied &&*/ !shamApplied && condRemaining > 0) {
                    if (!showOn) {
                        condApplied = true;
                    }
                    condRemaining--;
                } else {
                    cout << "N " << j << endl;
                    return;
                }
                break;
            case 'D':
                if (/*!hairDried &&*/ ((bathOpen && !showOn) || (!bathOpen)) && !shamApplied && !condApplied) {
                    hairDried = true;
                } else {
                    cout << "N " << j << endl;
                    return;
                }
                break;
            case 'A':
                if (/*hairDried &&*/ !bathOpen && !showOn /*&& !shamApplied && !condApplied*/) {
                    shamRemaining = 2;
                } else {
                    cout << "N " << j << endl;
                    return;
                }
                break;
            case 'B':
                if (/*hairDried &&*/ !bathOpen && !showOn /*&& !shamApplied && !condApplied*/) {
                    condRemaining = 2;
                } else {
                    cout << "N " << j << endl;
                    return;
                }
                break;

        }
    }
    cout << "Y" << endl;
}

int main() {
   
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        proc();
    }
    return 0;
}
