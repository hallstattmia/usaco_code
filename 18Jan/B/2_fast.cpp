#include <bits/stdc++.h>
using namespace  std;


//time complexity : O(n * 1000)

int main() {
  freopen("lifeguards.in", "r", stdin);
  freopen("lifeguards.out", "w", stdout);
  
  int n;
  cin >> n;
  vector<int> l(n), r(n);
  
  for (int i = 0; i < n; ++i) {
    cin >> l[i] >> r[i];
    r[i]--;
  }
  
  vector<int> all_ti(1001); 
  for (int i = 0; i < n; ++i) {
    for (int j = l[i]; j <= r[i]; ++j) {
      all_ti[j]++;
    }
  }
  
  int max_guard_time = 0;
  for (int fired_cow = 0; fired_cow < n; ++fired_cow) {
    vector<int> ti = all_ti; //[0,1000]
    
    for (int j = l[fired_cow]; j <= r[fired_cow]; ++j) {
        ti[j]--;
    }
    int guard_time = 0;
    for (int i = 0; i <= 1000; ++i) {
      guard_time += (ti[i] > 0); //true:1 false:0
    }
    
    max_guard_time = max(max_guard_time, guard_time);
  }
  
  cout << max_guard_time << "\n";
}
        
        
