#include <bits/stdc++.h>
using namespace  std;
template<class TH> void _dbg(const char *sdbg, TH h){ 
  cerr  <<  sdbg  <<  '='  <<  h  <<  endl; 
}
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
struct node{
  int cost,p1,p2,p3,p4, id;
};
//dsu : disjoin set unite
class dsu {
 public:
  vector<int> p;
  int n;
 
  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }
 
  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }
 
  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};
bool cmp(node a, node b) {
  return a.cost < b.cost;
}
int  main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout<<fixed<<setprecision(20);
  cin >> n;
  vector<node> a(n);
  dsu d(4 * n);
  vector<vector<int>> e(2 * n); 
  for (int i = 0; i < n; ++i) {
    cin >> a[i].cost >> a[i].p1 >> a[i].p2 >> a[i].p3 >> a[i].p4;
    a[i].p1--; a[i].p2--; a[i].p3--; a[i].p4--;
    a[i].id = i;
    e[a[i].p1].push_back(i * 4 + 0);
    e[a[i].p2].push_back(i * 4 + 1);
    e[a[i].p3].push_back(i * 4 + 2);
    e[a[i].p4].push_back(i * 4 + 3);     
    d.unite(i * 4 + 0, i * 4 + 1);
    d.unite(i * 4 + 2, i * 4 + 3);
  }
  
  for (int i = 0; i < 2 * n; ++i) {
    debug(e[i]);
    d.unite(e[i][0], e[i][1]);
  }
  sort(a.begin(), a.end(), cmp);
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    if (d.unite(a[i].id * 4 + 0, a[i].id * 4 + 2)){
       ans += a[i].cost;
     }
  }
  cout << ans << endl;
  return 0;
}

