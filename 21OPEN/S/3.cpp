#include <bits/stdc++.h>
using namespace  std;
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


int n, k, l;

vector<int> a, b, use;
bool check(int mid) {
  b.clear();
  for (int i = 0; i < mid; ++i) b.push_back(a[i]);
  vector<int> c(k, l);
  for (int i = b.size() - 1; i >= 0; --i) {
    int need = mid - b[i];
    if (need <= 0) continue;
    use.resize(k);
    for (int j = 0; j < k; ++j)  use[j] = 0;
    while (need > 0) {
      int cho = -1;
      for (int j = 0; j < k; ++j) if (!use[j]) {
        if (cho == -1 || c[j] > c[cho]) {
          use[j] = 1;
          cho = j;
        }
      }
      if (cho == -1) return false;
      if (c[cho] == 0) return false;
      c[cho]--;
      need--;
    }
  }
      
  return true;
}
//bool check(int mid) {
  //b.clear();
  //for (int i = 0; i < mid; ++i) b.push_back(a[i]);
  //vector<int> c(l + 1);
  //c[l] = k;
  //int up = l;
  //for (int i = b.size() - 1; i >= 0; --i) {
    //int need = mid - b[i];
    //if (need <= 0) continue;
    //if (c[up] + c[up - 1] < need) {
      //return false;
    //}
    //int g0 = min(c[up], need);
    //int g1 = need - g0;
    //c[up] -= g0;
    //c[up - 1] -= g1;
    //if (up > 1) c[up - 1] += g0;
    //if (c[up] == 0) up--;
  //}
      
  //return true;
//}
int  main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout<<fixed<<setprecision(20);
  cin >> n >> k >> l;
  a.resize(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(), a.end(), greater<int>());
  int lo = 0, hi = n;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;

    if (check(mid)) lo = mid + 1;
    else hi = mid - 1;
  }
  cout << lo - 1 << endl;
  return 0;
}

