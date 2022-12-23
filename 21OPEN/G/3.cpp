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
struct pt {
    long long x, y;
    pt() {}
    pt(long long _x, long long _y) : x(_x), y(_y) {}
    pt operator-(const pt& p) const { return pt(x - p.x, y - p.y); }
    long long cross(const pt& p) const { return x * p.y - y * p.x; }
    long long cross(const pt& a, const pt& b) const { return (a - *this).cross(b - *this); }
};
vector<pt> point;
int sgn(const long long& x) { return x >= 0 ? x ? 1 : 0 : -1; }

bool inter1(long long a, long long b, long long c, long long d) {
    if (a > b)
        swap(a, b);
    if (c > d)
        swap(c, d);
    return max(a, c) <= min(b, d);
}

bool check_inter(const pt& a, const pt& b, const pt& c, const pt& d) {
    if (c.cross(a, d) == 0 && c.cross(b, d) == 0)
        return inter1(a.x, b.x, c.x, d.x) && inter1(a.y, b.y, c.y, d.y);
    return sgn(a.cross(b, c)) != sgn(a.cross(b, d)) &&
           sgn(c.cross(d, a)) != sgn(c.cross(d, b));
}
int vis[101];
vector<int> cho;
vector<int> line[101];
long long ans;
bool check(int x) {
  line[x].clear();
  int tmp = 0;
  for (int y = 0; y < x; ++y) {
    bool ok = true;  
    for (int p = 0; p < x; ++p) {
      if (p == y) continue;
      for (auto q : line[p]) {
        if (q == y) continue;
        if (check_inter(point[cho[x]], point[cho[y]], point[cho[p]], point[cho[q]])) {
          ok = false;
          break;
        }
      } 
    } 
    if (ok) {
      tmp++;
      line[x].push_back(y);
    }
  }

  if (tmp == x && x <= 3) return true;
  if (tmp == 3) return true;
  return false;
}
void dfs(int dep) {
  if (dep == n) {
    debug(cho);
    ans++;
    return;
  }
  for (int i = 0; i < n; ++i) {
    if (vis[i]) continue;
    cho[dep] = i;
    vis[i] = 1;
    if (check(dep)) dfs(dep + 1);
    vis[i] = 0;
  }

}
int  main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout<<fixed<<setprecision(20);
  cin >> n;
  cho.resize(n);
  point.resize(n);
  for (int  i = 0; i < n; ++i) {
    cin >> point[i].x >> point[i].y;
  }
  dfs(0);
  cout << ans << endl;
  return 0;
}

