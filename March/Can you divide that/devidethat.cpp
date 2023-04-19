#include <bits/stdc++.h>

using namespace std;

void solve() {
  int a, b;
  cin >> a >> b;

  vector<int> counts(101, 0);
  for (int i = 0; i < a; ++i) {
    int x;
    cin >> x;
    counts[x]++;
  }

  for (int n = 1; n < b; ++n) { // b <= n <= 100 are ignored
    if (counts[n] % (n + 1) != 0) {
      cout << "no\n";
      return;
    }
    counts[n + 1] += counts[n] / (n + 1);
  }
  cout << "yes\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}