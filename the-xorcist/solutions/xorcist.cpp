#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int main(){
    
        int n, k;
        cin >> n;
        int a[n];
        cin >> a[0];
        for(int i=1; i<n; i++){
            int x;
            cin >> x;
            a[i] = x^a[i-1];
        }
        cin >> k;
        for(int t=0; t<k; t++){
            int l, r;
            cin >> l >> r;
            char c;
            if(l == 0){
                c = a[r] % 94 + 33;
            }
            else{
                c = (a[l-1]^a[r]) % 94 + 33;
            }
            cout << c;
        }        
    
    return 0;
}

