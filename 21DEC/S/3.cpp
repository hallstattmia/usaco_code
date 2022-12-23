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
#define eb emplace_back

//OutPut

template<class T> void ps(T x) {
  cout << x << endl;
}

template<class T> void ps_vec(T a) {
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

void task() {
  int n, m;
  cin >> n >> m;
  vi a(n), b(n);
  vector<ll> cnta(m + 1), cntb(m + 1);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    cnta[a[i]]++;
    cntb[b[i]]++;
  }
  vector<ll> pair_cnta( 2 * m + 1), pair_cntb(2 * m + 1);
  auto add = [&](vector<ll> cnt, vector<ll> &pair_cnt) {
    for (int i = 0; i <= m; ++i) {    
      for (int j = 0; j <= m; ++j) {
        pair_cnt[i + j] += cnt[i] * cnt[j];
      }
    }  
  };
  add(cnta, pair_cnta);
  add(cntb, pair_cntb);
  debug(cnta, cntb);
  debug(pair_cnta, pair_cntb);
  ll ans = 0;
  for (int i = 0; i <= 2 * m; ++i) {
     ans += pair_cnta[i];
     if (i) ans -= pair_cntb[i - 1];
     ps(ans);
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

