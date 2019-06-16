// Copyright 2019 National Olympiad in Informatics - Sri Lanka
// Author: pasinducw

#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            cout << '*';
        }
        cout << endl;
    }
    return 0;
}