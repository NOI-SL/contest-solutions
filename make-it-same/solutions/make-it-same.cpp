#include<bits/stdc++.h>
using namespace std;
#define pb push_back

struct s{
    int v1;
    int v2;
};

bool comp(s a, s b)
{
    if(a.v1==b.v1)return a.v2<b.v2;
    return a.v1<b.v1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        
        vector<int>a(n);
        vector<int>b(n);
        
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        
        if(n%2==1)
        {
            int p=(n/2);
            if(a[p]!=b[p]){
                cout<<"No\n";
                continue;
            }
        }
        
        vector<s>as(n/2);
        vector<s>bs(n/2);
        
        for(int i=0;i<n/2;i++)
        {
            int x,y;
            x=min(a[i],a[n-1-i]);
            y=max(a[i],a[n-1-i]);
            
            as[i].v1=x;
            as[i].v2=y;
            
            x=min(b[i],b[n-1-i]);
            y=max(b[i],b[n-1-i]);
            
            bs[i].v1=x;
            bs[i].v2=y;
        }
        
        sort(as.begin(),as.end(),comp);
        sort(bs.begin(),bs.end(),comp);
        
        int c=0;
        
        for(int i=0;i<n/2;i++)
        {
            if(as[i].v1==bs[i].v1 && as[i].v2==bs[i].v2)c++;
        }
        
        if(c==n/2)cout<<"Yes\n";
        else cout<<"No\n";
        
        
    }
    
    return 0;
}
 
