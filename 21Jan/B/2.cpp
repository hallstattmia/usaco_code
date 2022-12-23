#include <bits/stdc++.h>
using namespace  std;

int main() {
  int n; 
  cin >> n;
  //int s1 = 0, s2 = 0;
  //for (int i = 0;  i < n; ++i) {
    //int x; cin >> x;
    //if (x % 2 == 1) s1++;
    //else s2++;
  //}
  
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  
  int s1 = 0, s2 = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] % 2 == 1) s1++;
    else s2++;
  }
  int now = 2; //2:even, 1:odd
  int ans = 0;
  while (s1 > 0 || s2 > 0) {
    if (now == 2) {
       if (s2 > 0) {
         s2--;
         ans++;
         //put 1 even
       }
       else {
         if (s1 >= 2) {
           s1 -= 2;
           ans++;
           //put 2 odd
         } else{
            //s2 == 0 && s1 <= 1 &&(s1 > 0 || s2 > 0) =>s1 == 1
            ans--;
            s1 = 0;
            //last del 1 odd, put 2 odd last of last==>2|1|, remain = 3 ==> 2,1,3|
         }
       }
    } else {
      if (s1 >= 1) {
        s1--;
        ans++;
        //put 1 ood
      } else {
        break;
      }     
    }
    if (now == 1) now = 2;
    else now = 1;
  }
  cout << ans << "\n";
}
