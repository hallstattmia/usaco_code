#include<bits/stdc++.h>

using namespace std;
const int maxn = 50010;
int a[maxn][5];
vector<bitset<maxn>> flag;
int main() {
  freopen("cowpatibility.in", "r", stdin);
  freopen("cowpatibility.out", "w", stdout);
  int n;
  cin >> n;
  flag.resize(10000);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 5; ++j) {
      cin >> a[i][j];
      //b[a[i][j][i] = 1;
      flag[a[i][j]].set(i);
    }     
  }
  long long result = 0;   
  for (int i = 0; i < n; ++i) {
    bitset<maxn> ans;
    for (int j = 0; j < 5; ++j) ans |= flag[a[i][j]];
    result += n - ans.count();
  }
  cout << result / 2 << endl;
}
