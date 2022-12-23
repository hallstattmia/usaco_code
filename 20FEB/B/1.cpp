#include <bits/stdc++.h>
using namespace  std;

int main() {
  //input
  freopen("triangles.in", "r", stdin);
  freopen("triangles.out", "w", stdout);
  
  int n;
  cin >> n;

  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }
  
  //simulation
  auto simulation = [&](int i, int j, int k) {
      if (y[i] == y[j] && x[i] != x[j] && x[i] == x[k] && y[i] != y[k]) {
         return abs(x[j] - x[i]) * abs(y[k] - y[i]); 
      } 
      
       
      else 
        return 0;  // not triangle
  };
  
  
  //iterator all combines.
  int largest_triangle_area = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) 
      for (int k = 0; k < n; ++k) {
        if (i == j || i == k || j == k) continue;
        //triangle(i, j, k)
        largest_triangle_area = max(largest_triangle_area, simulation(i, j, k));
      }
      
   //output
   cout << largest_triangle_area << endl;
}
