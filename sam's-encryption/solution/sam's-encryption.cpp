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

vector<int> findSubstring(string s, vector<string>& w) {
        vector<int> v;
        int l = w[0].length();
        int n = s.length(), m = w.size();
        unordered_map<string, int> wm;
        
        for(auto i:w)   wm[i]++; //map for count of words in the array
            
        for(int i=0;i<=n-(m*l);i++){ //loop should run till length of string - (length of word * no. of words) as 
                                    after that no such combination will be possible due to less no. of characters respecitve to that needed to make a concatenation of worrds
            unordered_map<string, int> cnt; //map for count of substring from current index
            
            int j;
            for(j=0;j<m;j++){
                string curS = s.substr(i+l*j,l); //get the substring word of size l from current index + length no. of words found till now
                if(wm[curS] == 0 || wm[curS] == cnt[curS])  break; //if current substring is with not present in words array or
                 present more no. of times than in the words array then break
                cnt[curS]++;
            }
            if(j == m)  v.push_back(i); //if the whole words array is iterated then pus it inot vector
        }
        
        return v;
}

int main()
{
    io();
    
     string s;
    cin>>s;
    
    int n;
    cin>>n;
    
    vector<string>w(n);
    
    for(int i=0;i<n;i++)cin>>w[i];
    
    vector<int> v = findSubstring(s,w);
    
    for(int i=0;i<(int)v.size();i++)cout<<v[i]<<"\n";
    
    return 0;
} 
