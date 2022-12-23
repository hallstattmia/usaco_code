#include <bits/stdc++.h>
using namespace  std;

int main() {
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w",stdout);
    int n;
    cin >> n;
    vector<vector<int>> edges(n);    //vector<int> edges[n];  //0, 1
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x  >> y;
        --x; --y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, 1 + ((int)edges[i].size()));
    }
    cout << ans << endl;
}
  
  
  
  
  
    
    
    
      
