#include<bits/stdc++.h>
using namespace std;

bool isHint(char c){
    if(c=='A'||c=='C'||c=='M'||c=='N'||c=='O'||c=='I'||c=='a'||c=='c'||c=='m'||c=='n'||c=='o'||c=='i'||c=='-'){

        return true;

    }
    return false;
}

 string findPassword(string s) {
        
        vector<char> v;
        for(int i=0; i<s.length(); i++){
            if(isHint(s[i])){
                v.push_back(s[i]);
                s[i]='a';
            }

        }
        int cnt=0;
        reverse(v.begin(), v.end());
        for(int i=0; i<s.length(); i++){
            if(s[i]=='a'){
                s[i]=v[cnt++];
            }
        }


return s;

}
int main(){
    string s="The team members were hard to tell apart since they all wore their hair in a ponytail";
    cout<<findPassword(s);
}