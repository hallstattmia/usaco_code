#include <bits/stdc++.h>
using namespace  std;

const int maxn = 1e3 + 10;
long double C[maxn][maxn], pw[maxn], sum[maxn], sum2[maxn];
double mul(double x, int y) {
  if (y == 1) return x;
  double x2 = mul(x, y / 2);
  x2 = x2 * x2;
  if (y&1) x2 = x2 * x;
  return x2;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout<<fixed<<setprecision(20);
  int T, k;
  cin >> T >> k;
  T--;
  for (int i = 0; i <= T; ++i) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
  }
  pw[0] = 1;
  for (int i = 1; i <= T; ++i) {
    pw[i] = pw[i - 1] * 2;
  }
  sum[0] = C[T][0] / pw[T];
  for (int i = 1; i <= T; ++i) {
    sum[i] = sum[i - 1] + C[T][i] / pw[T];
    sum2[i] = sum2[i - 1] + i * C[T][i] / pw[T];
    
  }
  double ans = 0.5 * T;
  k--;
  while (k > 0) {                                             
    int up_ans = ans;
    while (up_ans < ans) up_ans++;
    long double P = sum[T] - sum[up_ans - 1];
    long double E2 = sum2[T] - sum2[up_ans - 1];
    int jump = min(int((up_ans - (1 - P) * ans) / E2) + 1, k);
    k -= jump;
    ans = mul(1 - P, jump) * ans + E2 * (1 - mul(1 - P, jump)) / P;
    
  }
  cout << ans + 1 << "\n";
  //Read the stuff at the bottom
}


