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

const int maxn = 1e6 + 10;

int n, m, nq, nk;
string str;
vector<int> a, b(7,-1e9), c(7, -1e9), vis(7);
vector<tuple<int, int, int>> ans;
//A,B,C,A+B,A+C,B+C,A+B+C
int work(int &x, int &y, int &z) {
  if (x == -1e9) {
    if (y != -1e9 && z != -1e9) {
      x = y + z;
      return 1;
    }
  }
  if (y == -1e9) {
    if (x != -1e9 && z != -1e9) {
      y = x - z;
      return 1;
    }
  }
  if (z == -1e9) {
    if (x != -1e9 && y != -1e9) {
      z = x - y;
      return 1;
    }
  }
  
  if (x != -1e9 && y != -1e9 && z != -1e9) {
    if (x != y + z) return -1e9;
  }
  return 0;
}
void check() {
  for (int i = 0; i < 7; ++i) b[i] = c[i];
  long long  ok = 1;
  while (ok > 0) {
    ok = 0;
    ok += work(b[6], b[5], b[0]);
    ok += work(b[6], b[4], b[1]);
    ok += work(b[6], b[3], b[2]);
    ok += work(b[5], b[2], b[1]);
    ok += work(b[4], b[2], b[0]); 
    ok += work(b[3], b[1], b[0]);
    if (ok < 0) return;
  }

  for (int i = 0; i < 7; ++i) if (b[i] <= 0) return;
  if (b[0] <= b[1] && b[1] <= b[2]) ans.push_back(make_tuple(b[0],b[1],b[2])); 
}
void dfs(int use) {
  if (use == n) 
  { 
    check();
    return;
  }
  for (int i = 0; i < 7; ++i) {
    if (vis[i]) continue;
    vis[i] = 1;
    c[i] = a[use];     
    dfs(use + 1);
    vis[i] = 0;
    c[i] = -1e9;
  }
  
}

void task() {
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  ans.clear();
  dfs(0);
  sort(ans.begin(), ans.end());
  ans.erase(unique(ans.begin(), ans.end()), ans.end());
  for (int i = 0; i < ans.size(); ++i) {
    int x, y, z;
    tie(x, y, z) = ans[i];
    debug(x,y,z);
  }
  cout << ans.size() << endl;

}
signed  main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout<<fixed<<setprecision(20);
  int T = 1;
  cin >> T;
  for (int ti = 1; ti <= T; ++ti) {
    task();
  }
  return 0;
}

