#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>

using namespace std;
template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;
  cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}
template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 42
#endif
int main() {
  int n;
  cin >> n;
  
  string a;
  cin >> a;
  long long ans = 0;
  //- L=1
  ans -= n; 
  //- L=2
  for (int i = 0; i < n - 1; ++i) {
    if (a[i] != a[i + 1]) ans -= 2;
  }  
  
  for (int i = 0; i < n; ++i) {
    int  L = i, R = i;
    while (L - 1 >= 0 && a[L - 1] != a[i]) --L;
    while (R + 1 < n && a[R + 1] != a[i]) ++R;
    ans += 1LL * (i - L + 1) * (R - i + 1);
  }
  
   
  cout << ans << "\n";
}
    
