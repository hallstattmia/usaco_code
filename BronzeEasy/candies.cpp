#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    if (i) cout << " ";
    cout << n / m + (n % m >= m - i);
  }
  cout << "\n";
}
