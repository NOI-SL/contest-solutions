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
        int n;
        cin>>n;
        
        string spell="";
        
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            
            sort(s.begin(),s.end());
            
            spell+=s[0];
        }
        
        sort(spell.begin(),spell.end());
        
        cout<<spell<<"\n";
    }
    
    
    return 0;
}
