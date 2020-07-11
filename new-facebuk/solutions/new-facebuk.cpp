// Author: Pasindu Wijesena

#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout<<#x<<": "<<x<<endl
#define rep(a,b) for(int a=0;a<b;a++)
#define loop(a,b,c) for(int a=(b);((b) < (c) ? a <= (c) : a >= (c)); ((b) < (c) ? (a)++ : (a)-- ))
#define gcd(a,b) __gcd(a,b) // gcd of two numbers
#define bitCount(a) __builtin_popcount(a) // number of ones in binary form
#define zeroCount(a) __builtin_clz(a) // number of zeros at the end in binary form

typedef long long ll;


ll mod(ll V, ll N){
    return ((V % N) + N) % N;
}

void dfs(int node, int code, int &edges, vector<int> &visited, vector<vector<int>> &E){
    if(visited[node]) return;
    visited[node] = code;
    for(auto v:E[node]){
        edges++;
        dfs(v, code, edges, visited, E);
    }
}

bool solve(){
    int N;
    cin>>N;
    vector<vector<int> > ND(1000, vector<int>());
    rep(i,N){
        int H,S;
        cin>>H>>S;
        S += 500;
        ND[H].push_back(S);
        ND[S].push_back(H);
    }
    
    vector<int> freq;
    vector<int> visited(1000, 0);
    int code = 1;
    rep(i,1000){
        freq.push_back(0);
        dfs(i, code, freq[code-1], visited, ND);
        code++;
    }
    
    int result = 0;
    for(auto f:freq){
        result = max(result, f);
    }
    cout<<(result/2)<<endl;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    rep(i,T){
        
        solve();
    }
    
    return 0;
}
