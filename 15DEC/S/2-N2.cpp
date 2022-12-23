#include<bits/stdc++.h>
using namespace std;

int main() {
  freopen("highcard.in", "r", stdin);
  freopen("highcard.out", "w", stdout);
  int n;
  cin >> n;
  vector<int> E(n);
  set<int> B;
  for (int i = 0; i < n; ++i) {
    cin >> E[i];
  }
  
  vector<int> use(2 * n + 1);
  for (int i = 0; i < n; ++i) {
    use[E[i]] = 1;
  }
  for (int i = 1; i <= 2 * n; ++i) {
    if (!use[i]) {
      B.insert(i);
    }
  } 
  int win_cnt = 0;

  for (int i = 0; i < n; ++i) {
    auto it = B.lower_bound(E[i]);
    if (it == B.end()) { //can't find 
      B.erase(B.begin());
    } {
      B.erase(it);
      win_cnt++;
    }
  } 
  cout << win_cnt << "\n";
}
      
