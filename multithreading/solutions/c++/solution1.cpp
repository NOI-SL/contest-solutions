// Copyright 2020 National Olympiad in Informatics - Sri Lanka
// Author: pasinducw

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin>>N;
    
    // we use a stack to store the currently running processes
    // https://www.youtube.com/watch?v=wjI1WNcIntg follow the link to learn about stacks
    stack<int> P;

    // the vector `running` is used to store whether a certain process is running 
    vector<bool> running(1e8+1, false);

    // `lastStep` is used to store the index (starting from 1) of the last instruction that 
    // was successfully executed
    // so, if we are breaking in the middle, `lastStep` would be less than N 
    int lastStep = 0;
    
    for(int i=0;i<N;i++) {
        string op;
        int id;
        cin>>op>>id;
        
        if(op == "RUN") {
            // program already running
            if(running[id]) break;
            
            P.push(id);  
            running[id] = true;
        } else {
            int top = P.size() ? P.top() : -1;
            if(top == id){
                P.pop();
                running[id] = false;
            }
            else break;
        }

        lastStep++;
    }
    
    // lastStep contains the index of the last successfull instruction, hence if lastStep < N, the faulty step would be N+1
    if(lastStep < N) cout<<lastStep+1<<endl;
    else if(P.size() == 0) cout<<0<<endl;
    else cout<<N+1<<endl;
    
    return 0;
}
