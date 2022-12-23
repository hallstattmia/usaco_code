#include <bits/stdc++.h>
using namespace  std;

int main() {
  freopen("shell.in", "r", stdin);
  freopen("shell.out", "w", stdout);
  int n; 
  cin >> n;
  int pos[4][n + 1], score[n + 1];
  
  pos[1][0] = 1; //* = 1, empty = 0  <=>pos[1][0] represents pop1[0]
  pos[2][0] = 0;
  pos[3][0] = 0;
  score[0] = 0;
  
  for (int i = 1; i <= n; ++i) {
      int a, b, g;
      cin >> a >> b >> g;
      for (int j = 1; j <= 3; ++j) {
          pos[j][i] = pos[j][i - 1];
      }
      
      swap(pos[a][i], pos[b][i]);
      score[i] = score[i - 1] + (pos[g][i] == 1);  
  }
  cout << score[n] << endl;
  for (int i = 0; i <= n; ++i) {
     printf("state=%d, pos1=%d pos2=%d pos3=%d score=%d\n", i, pos[1][i], pos[2][i], pos[3][i], score[i]); 
  }
      
        
  
  
  
}
