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

  
using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vii = vector<pii>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define re(n) for (int i = 0; i < n; ++i)
#define rep(i,a,b) for (int i = a; i < b; ++i)
#define eb emplace_back

//OutPut


void ps(ll x) {
  cout << x << endl;
}
void ps(char x) {
  cout << x << endl;
}
void ps(string x) {
  cout << x << endl;
}
void ps(vi a) {
  for (int i = 0; i < a.size(); ++i) {
    if (i) cout << " ";
    cout << a[i];
  }
  cout << endl;
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

int n, m, nq, nk;
string str;
vector<tuple<int, int, int>> edge;
vector<vector<int>> e;
vector<int> group, p;
void dfs(int x, int src) {
   for (auto y : e[x]) {
     if (group[y] != -1) continue;
     group[y] = group[src];
     dfs(y, src);
   }
  
}
bool check(int mid) {
  e.resize(n);// e[x][y] : x -> e[x][y]
  for (int i = 0; i < n; ++i) e[i].clear();
  for (int i = 0; i < m; ++i) {
    int x, y, z;
    tie(x, y, z) = edge[i];
    if (z >= mid) {
      e[x].push_back(y);
      e[y].push_back(x);
    }
  }
  group = vector<int>(n, -1);

  int group_count = 0; 
  for (int i = 0; i < n; ++i) {
    if (group[i] != -1) continue;
    group[i] = group_count++;
    dfs(i, i);
  }  
  for (int i = 0; i < n; ++i) {
    if (group[i] != group[p[i]]) return false;
  }
  return true;
}
void task() {
  cin >> n >> m;
  p.resize(n);
  for (int i = 0;  i < n; ++i) {
    cin >> p[i]; //(i, p[i]) connected
    --p[i];
  }

  for (int i = 0; i < m; ++i) {
    int x, y, z;
    cin >> x >> y >> z;
    --x; --y;
    edge.emplace_back(x, y, z);
  }
  int l = 1, r = 1e9, ans = -1;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (check(mid)) {
      l = mid + 1;
      ans = mid;
    } else {
      r = mid - 1;
    }
  } 
  if (ans >= 1e9) cout << -1 << endl;
  else cout << ans << endl;
  //Read the stuff at the bottom
}
signed  main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  setIO("wormsort");
  cout<<fixed<<setprecision(20);
  int T = 1;
  //cin >> T;
  for (int ti = 1; ti <= T; ++ti) {
    task();
  }
  return 0;
}

/* stuff you should look for
  * int overflow, array bounds
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * write down
*/
