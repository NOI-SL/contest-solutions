#include <bits/stdc++.h>

using namespace std;

void solve() {
    // taking inputs
    int n,l;
    cin >> n >> l;
    int k[n];
    for (int i=0; i<n; i++) {
        cin >> k[i];
    }
    int m;
    cin >> m;
    int q[m];
    for (int i=0; i<m; i++) {
        cin >> q[i];
    }

    // find the amount of total buckets required
    int totalBuckets = 0;
    for (int i=0; i<m; i++) {
        totalBuckets += q[i]/l + (q[i]%l != 0);
    }

    // find the number of trips required
    int ans = 0;
    for (int i=0; i<1000000; i++) {
        if (totalBuckets <= 0) {
            break;
        }
        totalBuckets -= k[i%n];
        ans += 1;
    }

    cout << ans << "\n";
}
 
int main(){
    solve();
}