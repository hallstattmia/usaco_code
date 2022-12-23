#include <bits/stdc++.h>
using namespace  std;


int simulation(int guess_init_pos) {

  freopen("shell.in", "r", stdin);  
  int n; 
  cin >> n;
  int pos[4], score;
  pos[1] = 0;
  pos[2] = 0;
  pos[3] = 0;
  pos[guess_init_pos] = 1; //* = 1, empty = 0  <=>pos[1][0] represents pop1[0]

  score = 0;
  
  for (int i = 1; i <= n; ++i) {
      int a, b, g;
      cin >> a >> b >> g;
    //   for (int j = 1; j <= 3; ++j) {
    //       pos[j][i] = pos[j][i - 1];
    //   }
      
      swap(pos[a], pos[b]);
      score = score + (pos[g] == 1); 
 
      //printf("state=%d, pos1=%d pos2=%d pos3=%d score=%d\n", i, pos[1], pos[2], pos[3], score); 
       
  }
  return score;   
    
    
    
}
int main() {
  
  

    int max_score = 0;
    max_score = max(max_score, simulation(1));
    max_score = max(max_score, simulation(2));
    max_score = max(max_score, simulation(3));
    freopen("shell.out", "w", stdout);
    cout << max_score << endl;

     
}
