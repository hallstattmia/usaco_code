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
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)


  
using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
using pll = pair<ll, ll>;

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define eb emplace_back
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
//OutPut

template<class T> void ps(T x) {
  cout << x << "\n";
}

template<class T> void ps_vec(T a) {
  for (int i = 0; i < a.size(); ++i) {
    if (i) cout << " ";
    cout << a[i];
  }
  cout << "\n";
}
#define ps_end(x) {ps(x); return;}


const int md = 1e9 + 7; //998244353 ;
const int dir[4][2] = {{-1,0}, {1, 0}, {0, -1}, {0, 1}};
template<class T> bool ckmin(T& a, const T& b) { 
  return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
  return a < b ? a = b, 1 : 0; }
void setIO(string s){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}
const int maxn = 1e6 + 10;
int x[maxn], y[maxn];
int xg, yg, n;

vector<pair<ll, ll>>v[50];
int half = 0;
void dfs(int dep, int s, long long px, long long py) {
  if (dep == half) {
    v[s].pb(make_pair(px,py));
    return;
  }
  dfs(dep + 1, s, px, py);
  dfs(dep + 1, s + 1, px + x[dep], py + y[dep]);
} 
long long ans[maxn];
void dfs2(int dep, int s, long long px, long long py) {
  if (dep == n) {
    for (int k = s; k <= n; ++k) {
      int L = lower_bound(v[k-s].begin(), v[k-s].end(), make_pair(xg - px, yg - py)) - v[k-s].begin();
      int R = upper_bound(v[k-s].begin(), v[k-s].end(), make_pair(xg - px, yg - py)) - v[k-s].begin();
      ans[k] += R - L;
    }
    return;
  }
  dfs2(dep + 1, s, px, py);
  dfs2(dep + 1, s + 1, px + x[dep], py + y[dep]);
} 
void task() {

  cin >> n;
  cin >> xg >> yg;
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }
  half = min(n, n / 2 + 3);
 
  dfs(0, 0, 0, 0);
  for (int k = 0; k <= n; ++k)
  sort(v[k].begin(), v[k].end());
  dfs2(half, 0, 0, 0);
  for (int k = 1; k <= n; ++k)
  cout << ans[k] << "\n";
  //Read the stuff at the bottom
}
signed  main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout<<fixed<<setprecision(20);
  int T = 1;
 // cin >> T;
  for (int ti = 1; ti <= T; ++ti) {
    task();
  }
  return 0;
}
