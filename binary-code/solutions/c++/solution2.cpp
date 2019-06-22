// Copyright 2019 National Olympiad in Informatics - Sri Lanka
// Author: chethiya

#include<iostream>

using namespace std;

void recurse(string &bits, int pos) {
    if (pos == bits.size()) {
        cout << bits << endl;
        return;
    }
    recurse(bits, pos + 1);
    if (bits[pos] == '0') {
        bits[pos] = '1';
    } else {
        bits[pos] = '0';
    }
    recurse(bits, pos + 1);
}

int main() {
    string bits;
    cin >> bits;
    cout << (1 << bits.size()) << endl;
    recurse(bits, 0);
    return 0;
}