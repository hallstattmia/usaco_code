#include <bits/stdc++.h>
using namespace  std;
//Time Complexity: O(n^2v)
int main() {
  int n;
  cin >> n;
  vector<int> target(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> target[i];
  } 
  
  vector<int> source(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> source[i];
  } 
  
  vector<int> oper(n + 1);
  for (int i = 1; i <= n; ++i) {
    oper[i] = target[i] - source[i];
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (oper[i] == 0) {
      continue;
    }

    int dir = 0;
    if (oper[i] > 0) dir = 1;  //up
    else dir = -1;//down; 
    while (oper[i] != 0) {
      oper[i] -= dir;
      ans++;
      for (int j = i + 1; j <= n; ++j) {
        if (dir == 1) {
          if (oper[j] > 0) {
            oper[j] -= dir;
          } else {
            break;
          }
        } else {
          if (oper[j] < 0) {
            oper[j] -= dir;
          }else {
            break;
          }
        }   
      }
    } 
  }
  
  cout << ans << "\n";
}
  
  
   
