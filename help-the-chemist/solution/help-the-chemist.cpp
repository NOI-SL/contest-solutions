#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
void io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int coun=0;

void dfs(int now,vector<int>g[],vector<bool>&v)
{
    coun++;
    v[now]=1;
    for(int i=0;i<(int)g[now].size();i++)
    {
        //cout<<g[now][i]<<"*";
        if(!v[g[now][i]])dfs(g[now][i],g,v);
    }
    
}

int main()
{
    io();
    
    int t;
    t=1;
    
    while(t--)
    {
        int m;
        cin>>m;
        
        vector<int>g[10001];
        
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
           // a--,b--;
            g[a].pb(b);
            g[b].pb(a);
            
        }
        
        vector<bool>v(10001,0);
        
        vector<int>ansarr;
        
        for(int i=0;i<10001;i++)
        {
            if(!v[i] && (int)g[i].size()>0)
            {
                coun=0;
                //cout<<v[i]<<" ";
                dfs(i,g,v);
                
                ansarr.pb(coun);
            }
        }
        
        cout<<(int)ansarr.size()<<"\n";
        
        sort(ansarr.begin(),ansarr.end());
        
        for(int i=0;i<(int)ansarr.size();i++)cout<<ansarr[i]<<"\n";
        
    }
    return 0;
}
