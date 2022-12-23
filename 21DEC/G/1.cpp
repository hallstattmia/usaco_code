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

void ps(int x) {
  cout << x << endl;
}
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
const long long INF = (ll)1e18;
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

void task() {
  int T, n, k;
  cin >> T >> n >> k;
 
  vi x(n), y(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }


  vector<int> p(1, 0);
  ll ans = 0;
  auto min_solve =[&]() {
    if (p.size() % 2 != 0) {
        ll s = min(y[p.front()], y[p.back()]);
        for (int i = 1; i < p.size() - 1; ++i) {
          if (i % 2 == 0 || x[p[i + 1]] - x[p[i - 1]] <= k) {
            s = min(s, (ll)y[p[i]]);
          }
        }
        ans += s;
      }
  };
  auto max_solve =[&]() {
    int n = p.size();

    vector<vector<ll>>  dp(n, vector<ll>(2)); //0:even, odd:1
    ll  oe[2][2] = {{-INF,  -INF}, {0, -INF}};

    //dp[i][0] = dp[k][0] (i - k - 1 % 2 ==0) dp[k][1] (i - k - 1 % 2 ==1, a[k+1] -a[k-1]<=maxK)
    int j = 0;
    ll s = 0;
    for (int i = 0; i < n; ++i) {
      
      while  (x[p[i]] -  x[p[j]] >  k) {
        oe[j&1][0] = max(oe[j&1][0], dp[j][0]);
        if (j == 0 || j == n - 1 || x[p[j+1]]-x[p[j - 1]] <=k) {
          oe[j&1][1] = max(oe[j&1][1], dp[j][1]);
        }
        ++j; 
      }
      dp[i][0] = max(oe[i&1][1], oe[1^(i&1)][0]) + y[p[i]];  
      dp[i][1] = max(oe[i&1][0], oe[1^(i&1)][1]) + y[p[i]];
      
      if ((n - i - 1)&1) {
        if (i == 0 || x[p[i + 1]] - x[p[i - 1]] <= k) s = max(dp[i][1],s);
      }
      else s = max(dp[i][0], s);      
    }
    ans += s;
  };
    
  for (int i = 1; i <= n; ++i) {
    if (i == n || x[i] - x[i - 1] > k) {
      if (T == 1) min_solve();
      else max_solve();
      p.clear();
    } 
    if (i < n)  p.pb(i);
  }
  cout << ans << "\n";
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

