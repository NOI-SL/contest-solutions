// Breath First Search
// Complexity: O ( n + m )

#include<bits/stdc++.h>
#define N 100002
using namespace std;
bool visited[N];

int factArr[10];

int main(){
    queue<pair<int,int>> q;

    int x,y;cin>>x>>y;
    q.push({x,0});

    factArr[0]=1;
    factArr[1]=1;

    for(int i=2;i<10;i++){
        factArr[i]=factArr[i-1]*i;
    }

    while (!q.empty()) {

        int tmpx = q.front().first;
        int len=q.front().second;
        q.pop();

        // printf("%i %i\n",tmpx,len);

        if(visited[tmpx]){
            // printf("-1\n");
            // return 0;
            continue;
        }

        if(tmpx==y){
            printf("%i\n",len);
            return 0;
        }

        visited[tmpx]=true;

        if(tmpx%2==0){
            q.push({tmpx/2,len+1});
        }

        if(tmpx*tmpx <= 100000 && tmpx<10000){
            q.push({tmpx*tmpx,len+1});
        }

        if(3*tmpx+1 <= 100000){
            q.push({3*tmpx+1,len+1});
        }

        if(tmpx<=8){
            q.push({factArr[tmpx],len+1});
        }

        q.push({__builtin_popcount(tmpx),len+1 });

    }

    printf("-1\n");
    return 0;


}
