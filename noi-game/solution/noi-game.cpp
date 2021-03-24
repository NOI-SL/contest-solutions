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


int main()
{
    io();
    
    string s;
    cin>>s;
    
    stack<char>st;
    
    int n=s.size();
    
    for(int i=0;i<n;i++)
    {
        if(st.empty())
        {
            st.push(s[i]);
            continue;
        }
        
        if(s[i]==st.top())
        {
            st.pop();
        }else st.push(s[i]);
    }
    
    string ans="";
    
    while(!st.empty())
    {
        ans+=st.top();
        st.pop();
    }
    
    reverse(ans.begin(),ans.end());
    
    if((int)ans.size()==0)cout<<"-1\n";
    else cout<<ans<<"\n";
    
    return 0;
}
