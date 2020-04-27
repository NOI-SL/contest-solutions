#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
#define MAXN 100008
int N;
int A[MAXN],B[MAXN];

int main(){
    scanf("%d",&N);

    for(int i=0;i<N;i++)
        scanf("%d",&A[i]);

    for(int i=0;i<N;i++)
        scanf("%d",&B[i]);

    sort(A, A+N);
    sort(B, B+N, greater<int>());

    int pair_sum = A[0]+B[0];

    for(int i=0;i<N;i++)
        if(A[i]+B[i]!=pair_sum){
            printf("-1");
            return 0;
        }

    for(int i=0;i<N;i++)
        printf("%d %d\n",A[i],B[i]);

    return 0;
}

