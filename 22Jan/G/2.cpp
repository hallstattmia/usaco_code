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
using pll = pair<ll, ll>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define eb emplace_back

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



void task() {
  ll n, m;
  cin >> n >> m;
  vector<tuple<int, int, int>> oper;
  vector<int> addV(n, n);
  vector<tuple<int, int, int>> addE;
  vector<int> useE(m); 
  for (int i = 0; i < m; ++i) {
    char ch; int x, y;
    cin >>  ch;
    if (ch == 'D') {
      cin >> x; --x;
      addV[x] = 1;
      oper.eb(i, x, -1);
    } else if (ch == 'A') {
      cin >> x >> y; --x; --y;
      debug(i, x, y);
      addE.eb(i, x, y);
    } else {
      cin >> x; --x;
      int t, u, v;
      tie(t, u ,v) = addE[x];
      oper.eb(i, u , v); 
      useE[t] = 1;
    }
  }
  for (int i = 0; i < addE.size(); ++i) {
    int t, u, v;
    tie(t, u ,v) = addE[i];
    if (useE[t]) continue;
    oper.eb(m, u,v); 
  }
  for (int i = 0; i < n; ++i) {
    if (addV[i] == n) {
      oper.eb(m, i, -1);
    }
  }
  reverse(all(oper));
  vector<vector<int>> b(n);
  vector<int> pa(n), have(n), ans(n);
  for (int i = 0; i < n; ++i) {
    b[i].push_back(i);
    pa[i] = i;
    have[i] = 0;
  }

  for (int i = 0; i < oper.size(); ++i) {
    int z, x, y;
    tie(z, x, y) = oper[i];
    if (y == -1) {
      int fx = pa[x];
      
      if (have[fx]) continue;
      have[fx] = 1;
      for (auto x : b[fx]) {
        debug(x, fx);
        ans[x] = max(ans[x], z);
      }
    } else {
      int fx = pa[x], fy = pa[y];
      bool ok = have[fx] || have[fy];
      if (ok) {
        if (!have[fx]) {
          for (auto x : b[fx]) {
            ans[x] = max(ans[x], z);
          }
        }
        if (!have[fy]) {
          for (auto x : b[fy]) {
            ans[x] = max(ans[x], z);
          }
        }
        have[fx] = have[fy] = 1;
      }
      if (b[fx].size() > b[fy].size()) {
        swap(fx, fy);
      }
      for (auto x : b[fx]) {
        pa[x] = fy;
        b[fy].push_back(x);
      }
    }
  }
  for (int i = 0; i < n ;++i) {
    cout << ans[i] << "\n";
  }
   
    
  
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

