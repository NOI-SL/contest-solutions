#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;
#define MAXN 20005
#define MAXR 50005
#define MAXM 5005
#define loop(i,N) for(int i=0;i<N;i++)

int N,R,M;
int P[MAXN];// patients
int D[MAXN],d;// last updated day

vector <int> adj[MAXN]; // adjecency list
queue <int> q[MAXN];

int main(){

    scanf("%d %d",&N,&R);

    loop(i,R){ // create adj list from input
        int s,e;
        scanf("%d %d",&s,&e);
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    scanf("%d",&M);

    loop(i,M){
        int c,p;
        scanf("%d %d",&c,&p);
        P[c]=p;
        q[0].push(c);
    }

    while(!q[d].empty()){
        int s = q[d].front(); q[d].pop();
        int newP = (int)P[s]/2;
        for(auto u:adj[s]){
            if(P[u]>newP) continue; // already infected to more people in the city
            if(P[u]==newP){
                D[u] =min(D[u],D[s]+1);
            }
            else{
                P[u] =newP;
                D[u] =D[s]+1;
            }
            q[d+1].push(u);        
        }
        if(q[d].empty()) d++;
    }

    long long Pmax=0;

    loop(i,N){
        Pmax+=(long long)P[i];
      
    }

    printf("%d %lld",d,Pmax);
    return 0;
}
