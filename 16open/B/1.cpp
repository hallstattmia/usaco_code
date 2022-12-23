#include <bits/stdc++.h>
using namespace  std;

int main() {
   freopen("diamond.in", "r", stdin);
   freopen("diamond.out", "w", stdout);
   
   //Input
   int n, k;
   cin >> n >> k;
   vector<int> diamonds(n);
   for (int i = 0; i < n; ++i) {
     cin >> diamonds[i];
   }
   //sort order from smallest to largest
   sort(diamonds.begin(), diamonds.end()); 
   int maxChoose = 0; // real choose >= 0
   for (int smallest_postion = 0; smallest_postion < n; ++smallest_postion) 
     for (int largest_postion = smallest_postion; largest_postion < n; ++largest_postion) {
       if (diamonds[largest_postion] - diamonds[smallest_postion] <= k) {
         maxChoose = max(maxChoose, largest_postion - smallest_postion + 1);
       }
       
     }
   //Output
   cout << maxChoose << endl;  
   
  
}
