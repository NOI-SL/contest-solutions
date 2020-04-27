#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;
#define MAXN 1010
int N,pitch[MAXN];
int maxRange[MAXN][MAXN],minRange[MAXN][MAXN];
bool isMelody[MAXN][MAXN];
int dp[MAXN];

int main(){
  //while(true){
    cin>>N;

    for(int i=0;i<N;i++)
        cin>>pitch[i];

    for(int i=0;i<N;i++){
        maxRange[i][i] = minRange[i][i] =pitch[i];
        for(int j=i+1;j<N;j++){
            maxRange[i][j] = max(pitch[j],maxRange[i][j-1]);
            minRange[i][j] = min(pitch[j],minRange[i][j-1]);
        }
    }

    for(int i=0;i<N-2;i++)
        for(int j=i+2;j<N;j++){ // songs are longer than 3 minutes
            if(maxRange[i+1][j-1] < pitch[i] && maxRange[i+1][j-1] < pitch[j]) isMelody[i][j] = true;
            if(minRange[i+1][j-1] > pitch[i] && minRange[i+1][j-1] > pitch[j]) isMelody[i][j] = true;

        }

    dp[0] = dp[1] =0; // song count after addding the ith elements

    for(int i=2;i<N;i++){
        dp[i] = dp[i-1];
        for(int j=0;j<=i-2;j++)
            dp[i] = max((j>0? dp[j-1]:0)+isMelody[j][i],dp[i]);
      //  cout<<i<<' '<<dp[i]<<endl;
    }
    cout<<dp[N-1]<<endl;
   // cout<<"done";

 //}
 return 0;
}
