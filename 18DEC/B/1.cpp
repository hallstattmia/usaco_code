#include <iostream>
using namespace std;

int main() {
  freopen("mixmilk.in", "r", stdin);
  freopen("mixmilk.out", "w", stdout);
  int a[3], b[3];
  for (int i = 0; i < 3; ++i) cin >> a[i] >> b[i];
  for (int t = 0; t < 100; ++t) { 
       int i = t % 3;
       int j = (i + 1) % 3;
       int delta = min(b[i], a[j] - b[j]);
       b[i] -= delta;
       b[j] += delta;
  }
  for (int i = 0; i < 3; ++i) cout << b[i] << endl;
  
}
