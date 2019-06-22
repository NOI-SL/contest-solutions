#include <iostream>
#include <algorithm>
// Copyright 2019 National Olympiad in Informatics - Sri Lanka
// Author: vpj

#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;

string s;

void change(int n) {
    if (n >= s.size()) {
        cout << s << endl;
        return;
    }

    change(n + 1);
    s[n] = s[n] == '0' ? '1' : '0';
    change(n + 1);
}

int main() {
    cin >> s;

    cout << (1 << s.size()) << endl;

    change(0);

    return 0;
}
