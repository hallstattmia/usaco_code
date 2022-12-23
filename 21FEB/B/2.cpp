#include <bits/stdc++.h>
using namespace  std;
const int dir[4][2] = {{-1,0}, {1, 0}, {0, -1}, {0, 1}};
int main() {
  int n;
  cin >> n;
  
  vector<int> x(n + 1), y(n + 1);
  //cin >> x[1] >> y[1];
  //cin >> x[2] >> y[2];
  //...
  //cin >> x[n] >> y[n];
  vector<vector<int>> gird(1001, vector<int>(1001, 0));
  vector<vector<int>> cnt_adj_cow(1001, vector<int>(1001, 0));
  
  for (int i = 1; i <= n; ++i) {
    cin >> x[i] >> y[i];
   
    //i = 1; cin >> x[1] >> y[1];
    //i = 2; cin >> x[2] >> y[2];
    //...
    //i = n; cin >> x[n] >> y[n];
  }
  vector<int> ans(n + 1);
  for (int t = 1; t <= n; ++t) {
    ans[t] = ans[t - 1];
    gird[x[t]][y[t]] = 1;
    for (int k = 0; k < 4; ++k) {
      int adj_x = x[t] + dir[k][0];
      int adj_y = y[t] + dir[k][1];
      if (adj_x >= 0 && adj_x <= 1000 && adj_y >= 0 && adj_y <= 1000) {
        if (gird[adj_x][adj_y]) {
          cnt_adj_cow[x[t]][y[t]]++;
          cnt_adj_cow[adj_x][adj_y]++;
          if (cnt_adj_cow[adj_x][adj_y] == 3) {
            ans[t]++;  //unsafe ->safe
          }
          if (cnt_adj_cow[adj_x][adj_y] == 4) {
            ans[t]--; //safe ->unsafe
          }
        }
      }
    }
    if (cnt_adj_cow[x[t]][y[t]] == 3) {
      ans[t]++;
    }
    cout << ans[t] << "\n";
  }
}
