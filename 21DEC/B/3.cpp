#include <bits/stdc++.h>
using namespace  std;

//Time Complexity: O(n^2K)

int main() {
  int T; cin >> T;
  while (T--) {
    int n, k; cin >> n >> k;
    vector<string> str(n);
    for (int i = 0; i < n; ++i) cin >> str[i];
    
    vector<vector<long long>> dp[2][k + 1];
    for (int i = 0; i < 2; ++i)
      for (int j = 0; j <= k; ++j) dp[i][j] = vector<vector<long long>>(n, vector<long long>(n, 0));
    if (str[0][1] == '.') dp[1][0][0][1] = 1;
    if (str[1][0] == '.') dp[0][0][1][0] = 1;
    for (int turn = 0; turn <= k; ++turn)
      for (int dir = 0; dir < 2; ++dir) 
        for (int i = 0; i < n; ++i)
          for (int j = 0; j < n; ++j) {
             if (i + 1 < n && str[i + 1][j] == '.') {
                int next_dir = 0, next_turn = turn;
                if (next_dir != dir) next_turn++;
                if (next_turn <= k) dp[next_dir][next_turn][i + 1][j] += dp[dir][turn][i][j]; 
             }
             
             if (j + 1 < n && str[i][j + 1] == '.') {
                int next_dir = 1, next_turn = turn;
                if (next_dir != dir) next_turn++;
                if (next_turn <= k) dp[next_dir][next_turn][i][j + 1] += dp[dir][turn][i][j]; 
             }  
          
          }
    long long ans = 0;
    for (int turn = 0; turn <= k; ++turn)
      for (int dir = 0; dir < 2; ++dir) {
        ans += dp[dir][turn][n - 1][n - 1];
      }
    cout << ans << "\n"; 
  }
  
}
    
