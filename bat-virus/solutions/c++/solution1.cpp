#include<bits/stdc++.h>

using namespace std;

vector<int>a[200000];
vector<int>ans(200000,0);
vector<int>days(200000,0);
vector<bool>v(200000,0);
int maxDays=0;
long long tot=0;
    
priority_queue<pair<int,int> >q;
void bfs() 
{
    while(!q.empty())
    {
        int c=q.top().first;
        int p=q.top().second;
        q.pop();
        ans[p]=max(ans[p],c);
        
        if(c/2>0)
        {
            int siz = a[p].size();
            for(int i=0;i<siz;i++)
            {
                if(v[a[p][i]]==0 && ans[a[p][i]]<=c/2)
                {
                    q.push(make_pair(c/2,a[p][i]));
                    days[a[p][i]]=days[p]+1;
                    v[a[p][i]]=1;
                }
            }         
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,r;
    cin>>n>>r;
    
    for(int i=0;i<r;i++)
    {
        int x,y;
        cin>>x>>y;
        
        a[x].push_back(y);
        a[y].push_back(x);

    }
    
    int m;
    cin>>m;
    
    for(int i=0;i<m;i++)
    {
        int p,c;
        cin>>p>>c;
        if(c>0)
        {
            for(int i=0;i<n;i++)v[i]=0;
            v[p]=1;
            days[p]=1;
            q.push(make_pair(c,p));
            bfs();
        }
    }
    
    for(int i=0;i<n;i++){
        tot+=ans[i];
        maxDays=max(maxDays,days[i]);
    }
    cout<<maxDays<<" "<<tot<<endl;
  
    return 0;
}
