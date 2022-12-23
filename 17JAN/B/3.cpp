#include<iostream>
#include<vector>
using namespace std;

int main() {
  freopen("cowtip.in", "r", stdin);
  freopen("cowtip.out", "w", stdout);
  int n;  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  string str;
  for (int i = 0; i < n; ++i) {
    cin >> str;
    for (int j = 0; j < n; ++j) {
      a[i][j] = str[j]  - '0'; //'5' - '0'  = 5
    }
  }
  int oper_s = 0; 
  for (int i = n - 1; i >= 0; --i)
    for (int j = n - 1; j >= 0; --j) {
       if (a[i][j] == 1) {
         oper_s++;
         
         for (int i1 = 0; i1 <= i; ++i1)
            for (int j1 = 0; j1 <= j; ++j1) {
               a[i1][j1] = 1 - a[i1][j1];
            }
      }
    }   

  cout << oper_s << "\n";
  
  
}
