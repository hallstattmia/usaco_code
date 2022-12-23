#include <bits/stdc++.h>
using namespace  std;

int main() {
  freopen("sleepy.in", "r", stdin);
  freopen("sleepy.out", "w", stdout);
  int n; cin >> n;
  
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  //4 2 1 3 5 6->4
  //4 3 2 5 1 6->2
  int s = 1;
  for (int i = n - 2; i >= 0; --i) {
    if (a[i + 1] > a[i]) {
      s++;
    } else {
      break;
    }
  }
  cout << n - s << "\n";
}
  
