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
 
  

  cin >> n;
  vector<int> a(n), cnt(n);
  vector<ll> h(n + 1);
  
  for (int i = 0; i < n; ++i) {
      cin >> a[i];  --a[i];

  }
  ll K = 1e6;
  ll K2 = 1e12;
  vector<vector<pair<int, ll>>> edge(n);
  for (int i = 0; i < n; ++i){
    if (i == a[i]) continue;
    edge[i].push_back(mp(a[i], K));
    if (a[i] < n - 1) edge[a[i] + 1].push_back(mp(i, - K - 1));
  }
  for (int i = 0; i < n - 1; ++i) {
    edge[i].push_back(mp(i + 1, K2));
    edge[i + 1].push_back(mp(i, 0));
  }

  queue<int> q;
  vector<ll> ans(n, 1e18);
  vector<int> v(n);
  q.push(0);
  ans[0] = 0;
  while (!q.empty()) {
    int x = q.front(); q.pop();
    v[x] = 0;
    for (auto p : edge[x]) {
      int y = p.fi; ll z = p.se;
      if (ans[y] > ans[x] + z) {
        ans[y] = ans[x] + z;
        if (!v[y]) {
          q.push(y);
          v[y] = 1;
        }
      }
    } 
  }
  
  ps(K);
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << "\n";
  }

  //Read the stuff at the bottom
}
signed  main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout<<fixed<<setprecision(20);
  int T = 1;
  //cin >> T;
  for (int ti = 1; ti <= T; ++ti) {
    task();
  }
  return 0;
}

