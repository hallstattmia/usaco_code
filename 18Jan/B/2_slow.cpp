#include <bits/stdc++.h>
using namespace  std;

//time complexity : O(n * n * 1000)
/*
 * 定义：泳池的守卫时间=
至少一头奶牛守护的时间点个数
目标：去除一头牛，剩下牛的最大泳池守卫时间

预处理: N头牛的守卫情况
pattern: 
去除第i头牛，剩下牛的泳池守卫时间 (1<=i<=n)
（显然pattern包含目标）

求解pattern：N头牛的守卫情况->N-1头牛的守卫情况 O(1000) 
* */



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
  
  int max_guard_time = 0;
  for (int fired_cow = 0; fired_cow < n; ++fired_cow) {
    vector<int> ti(1001); //[0,1000]
    
    for (int i = 0; i < n; ++i) {
      if (i == fired_cow) continue;
      
      for (int j = l[i]; j <= r[i]; ++j) {
        ti[j]++;
      }
    }
    int guard_time = 0;
    for (int i = 0; i <= 1000; ++i) {
      guard_time += (ti[i] > 0); //true:1 false:0
    }
    
    max_guard_time = max(max_guard_time, guard_time);
  }
  
  cout << max_guard_time << "\n";
}
        
        
