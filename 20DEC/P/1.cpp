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
#define int ll
  
using ll = long long;
using ld = long double;
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
const int maxn = 5e3 + 10;
void upd(ll &x, ll y) {
  x += y;
  x %= md;
}
int n, m, nq, nk;
string str;
vector<vector<ll>> dp, dp2;
vi a(n), b(n);
void init_dp(vector<vector<ll>> &dp) {
  
  dp[0][0] = 1;
  int use_box = 0;
  debug(a);
  debug(b);
  for (int i = 0; i < n; ++i) {
    int now_box = use_box;
    while (now_box < n && a[i] <= b[now_box]) now_box++;
    int p = now_box - use_box;
    debug(now_box, p);
    for (int j = 0; j <= use_box; ++j) {
        upd(dp[i + 1][j + p], dp[i][j]);
        if (j + p) upd(dp[i + 1][j + p - 1], dp[i][j] * (j + p));
    }
    use_box = now_box;    
  }
}
void init_dp2(vector<vector<ll>> &dp) {
  dp[0][0] = 1;
  int use_box = 0;
  debug(a);
  debug(b);
  for (int i = 0; i < n; ++i) {
    int now_box = use_box;
    while (now_box < n && b[i] >= a[now_box]) now_box++;
    int p = now_box - use_box;
    debug(now_box, p);
    for (int j = 0; j <= use_box; ++j) {
        upd(dp[i + 1][j + p], dp[i][j]);
        if (j + p) upd(dp[i + 1][j + p - 1], dp[i][j] * (j + p));
    }
    use_box = now_box;    
  }
}
void task() {
  cin >> n;
  a.resize(n);
  b.resize(n);
  re(n) cin >> a[i];
  re(n) cin >> b[i];
  dp = vector<vector<ll>>(n + 1, vector<ll> (n + 1, 0));
  dp2 = vector<vector<ll>>(n + 1, vector<ll> (n + 1, 0));
  sort(a.begin(), a.end(), greater<int>());
  sort(b.begin(), b.end(), greater<int>());
  init_dp(dp);
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  init_dp2(dp2);
  ll ans = 0;
  sort(a.begin(), a.end(), greater<int>());
  sort(b.begin(), b.end(), greater<int>());
  int now_box = 0;
  vi p(n + 1);
  for (int i = 0; i < n;++i) {
    while (now_box < n && a[i] <= b[now_box]) now_box++;
    p[i + 1] = now_box;
  }

  vi fact(n + 1);
  fact[0] = 1;
  for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i % md;
  debug(p);

  debug(fact);
  
  b.resize(n + 2);
  int last = 0;
  for (int i = 1; i <= n;++i) {
    int nx = i - 1, pre = i;
    int must = p[i] - p[i - 1]; // box
   
    int must2 = 0;   //people
    int zz = 0;
    for (int j = 0; j < n; ++j) if (b[j] < a[i-1]) zz = max(zz, b[j]);
    for (int j = i; j < n; ++j) if (a[j] > zz) must2++;
    for (int j = 0; j <= n - must; ++j) {  //j box ==>j + must box
      if (j + must - must2 < 0) continue;
      
      int cnt = dp[nx][j] * dp2[n - p[pre]][j + must - must2] % md * fact[j + must];
      upd(ans, cnt);
     
    }
    debug(ans); 
  }
  if (a[0] <= b[0]) {
    upd(ans, dp2[n][0]);
  }
  cout << ans << endl;
        
  
  //Read the stuff at the bottom
}
signed main() {
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

/* stuff you should look for
  * int overflow, array bounds
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * write down
*/
