#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
    int t;
    cin>>t;
    
    while(t--)
    {
        string s;
        cin>>s;
        
        sort(s.begin(),s.end());
        
        bool yes=1;
        
        for(int i=1;i<s.size();i++)
        {
            if(s[i]-s[i-1]!=1)
            {
                yes=0;
                break;
            }
        }
        
        if(yes)cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
