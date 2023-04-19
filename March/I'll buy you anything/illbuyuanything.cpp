```cpp20
#include<bits/stdc++.h>
using namespace std;
struct DSU{
    vector<int>parent,sz;
    DSU(int n){
        parent.resize(n);
        sz.resize(n,1);
        iota(parent.begin(),parent.end(),0);
    }
    int findsets(int v){
        if (v == parent[v]){
            return v;
        }
        parent[v] = findsets(parent[v]);
        return parent[v];
    }
    bool unionset(int u,int v){
        u = findsets(u);
        v = findsets(v);
        if (u == v){
            return false;
        }
        if (sz[v] > sz[u]){
            swap(u,v);
        }
        parent[v] = u;
        sz[u]+=sz[v];
        return true;
    };
};
const int MXN = 1e5;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    DSU st(n);
    vector<int>arr(n);
    vector<vector<int>>adj(MXN + 1);
    for (int i = 0;i<n;++i){
        cin>>arr[i];
        adj[arr[i]].push_back(i);
    }
    long long ans = 0;  
    for (int i = MXN;i>=1;--i){
        int v = -1;
        for (int j = i;j<=MXN;j+=i){
            for (auto x:adj[j]){
                if (v == -1){
                    v = x;
                }        
                else{
                    ans += i * st.unionset(v,x);    
                }                            
            }        
        }
    }
    cout<<ans<<'\n';
    return 0;
}
```
