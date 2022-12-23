#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> str(n);
  for (int i = 0; i < n; ++i) {
    cin >> str[i];
  }
  int sumx = 0, sumy = 0, cnt = 0;
  for (int i = 0; i < n; ++i) 
    for (int j = 0 ; j < m; ++j) {
      if (str[i][j] == 'B') {
        sumx += i;
        sumy += j;
        cnt++;
      }
    }
  sumx /= cnt;
  sumy /= cnt;
  cout << sumx + 1 << " " << sumy + 1 << "\n";
}
  
