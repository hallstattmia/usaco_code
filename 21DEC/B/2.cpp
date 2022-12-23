#include <bits/stdc++.h>
using namespace  std;
//Time Complexity: O(n)
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> d(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> d[i];
  } 
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    int x; cin >> x;
    d[i] -= x;
    ans += max(0, d[i] - d[i - 1]);
  } 
  ans += max(0, 0 - d[n]);
  cout << ans << "\n";
}
