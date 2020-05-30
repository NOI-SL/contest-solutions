#include <bits/stdc++.h>
using namespace std;

const int ADD = 2;
const int REMOVE = 0;
const int TELL = 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N,M;
    cin>>N>>M;
    vector<pair<int, int>> E;
    
    for(int i=0;i<N;i++){
        int h; cin>>h;
        E.push_back({h, TELL});
    }
    
    for(int i=0;i<M;i++){
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        if(x1==x2) continue;
        E.push_back({min(x1,x2), ADD});
        E.push_back({max(x1,x2), REMOVE});
    }
    
    sort(E.begin(), E.end());
    long long result = 0;
    long long lines = 0;
    for(auto &e:E){
        if(e.second == REMOVE) lines--;
        if(e.second == TELL) result += lines;
        if(e.second == ADD) lines++;
        // cout<<e.first<<':'<<e.second<<' '<<lines<<"\t"<<result<<endl;
    }
    cout<<result<<endl;
    return 0;
}
