// Problem: Knucles Range
// Time Complexity: 	n*log(n)
// Space Complexity:	2*n

// Segment tree : sum,min,max,gcd, bit operations
// query and update O(log n)
// pre-process O(n)

// Stores values in n to 2n-1 in treeArr
// Note: n must be a power of 2

#include <bits/stdc++.h>
using namespace std;
#define N 131078

int treeArr[2 * N];
int n;
long long h;
int nn;

int query(int a, int b){
    if (b < 0 || a > nn - 1)
        return 0;
    a += n;
    b += n;
    int s = 0;

    while (a <= b){
        if (a & 1) s = max(treeArr[a++], s);
        if (!(b & 1)) s = max(treeArr[b--], s);

        a = a >> 1;
        b = b >> 1;
    }
    return s;
}

void update(int k, int x){
    k += n;
    treeArr[k] = x;

    for (int i = k >> 1; i > 0; i >>= 1){
        treeArr[i] = max(treeArr[i << 1], treeArr[i << 1 | 1]);
    }
}

//  build(int arr[]) - no need for this problem only for your knowladge
void build(int arr[]){ // arr[] length n
    for (int i = 0; i < n; i++){
        treeArr[i + n] = arr[i];
    }

    for (int i = n - 1; i > 0; i--){
        treeArr[i] = max(treeArr[i << 1], treeArr[i << 1 | 1]);
    }
}

int main(){

    cin >> nn >> h;

    n = int(pow(2, ceil(log(nn) / log(2))));

    long long hills[nn];
    long long heights[nn];

    for (int i = 0; i < nn; i++){
        cin >> hills[i];
        heights[i] = hills[i];
    }

    sort(heights, heights + nn);

    for (int i = nn - 1; i >= 0; i--){
        long long hl = hills[i] - h;
        long long hu = hills[i] + h;

        int ub = lower_bound(heights, heights + nn, hl) - heights;
        int lb = lower_bound(heights, heights + nn, hu) - heights;

        if (heights[ub] != hl) ub--;

        int dpmax = max(query(0, ub), query(lb, nn - 1));
        int pos = lower_bound(heights, heights + nn, hills[i]) - heights;

        update(pos, dpmax + 1);
    }
    cout << query(0, nn - 1) << endl;
}
