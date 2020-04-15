// Copyright 2020 National Olympiad in Informatics - Sri Lanka
// Author: pasinducw

#include <bits/stdc++.h>
using namespace std;


int main() {
    
    // totalNumbers will store the count of all the numbers in the lists
    int N, S = 0, totalNumbers = 0;
    
    // read input for N
    cin>>N;
    
    // create a vector of size `N` and of type int to store the lengths of the N lists
    vector<int> C(N);
    
    // read input for the N lists, while updating totalNumbers and S
    for(auto &c: C) {
        cin>>c;
        totalNumbers += c;
        S = max(S, c);
    }
    
    // create a vector of size `totalNumbers` and of type int to store all the numbers in the lists
    vector<int> V(totalNumbers);
    // read input for the numbers
    for(auto &v: V) cin>>v;
    
    // output the length of a single list (S has the maximum of all C values)
    cout<<S<<endl;
    
    // print the starting positions
    for(int i=0; i<N*S; i+=S) cout<<i<<' ';
    cout<<endl;
    
    
    int offset = 0;
    
    // we append zeros to the lists to match all their lenghts to S
    for(auto &c: C) {
        for(int i=0;i<c; i++) cout<<V[i + offset]<<' ';
        for(int i=0;i<(S-c); i++) cout<<0<<' ';
        offset += c;
    }
    cout<<endl;
    
    return 0;
}
