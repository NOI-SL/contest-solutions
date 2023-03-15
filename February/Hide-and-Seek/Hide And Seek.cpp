#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;cin>>t;while(t--){
    int n;cin>>n;
    vector<string> names(n);
    for(int i=0;i<n;++i) {cin>>names[i];}
    cin.ignore();
    string s;
    getline(cin,s);
    // Counting words in rhyme
    stringstream ss(s);
    int wc = 0;
    while(ss>>s) {
      ++wc;
    }
    // Removing excess friends
    while(names.size()>wc){
      names.pop_back();
    }
    // iterate eliminations
    while(names.size()>1){
      int m = names.size();
      int target = (wc)%m;
      target = (target==0) ? m-1:target-1;
      // Removing eliminated friend
      names.erase(names.begin()+(target));
    }
    // last remaining friend
    cout<<names[0]<<endl;
  }
}