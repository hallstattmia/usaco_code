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
int b;
void task() {
  ll n;
  cin >> n;
  vector<int> fa(n + 1), l(n + 1), r(n + 1);
  
  for (int i = 2; i <= n; ++i) {
    cin >> fa[i];
  }
  for (int i = 1 ; i < n + 1; ++i) {
    cin >> l[i] >> r[i];
  }
  auto check = [&](int mid, bool print) {
    vector<int> L(n + 1), R(n + 1), cl(n + 1), cr(n + 1);
    for (int i = n; i >= 1; --i) {
        L[i] = l[i] - mid;
        R[i] = r[i] + mid;
    }
    for (int i = n; i >= 2; --i) {
      L[fa[i]] = max(L[fa[i]], L[i]);
      R[fa[i]] = min(R[fa[i]], R[i]);
    }
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; ++i) {
      cl[i] = max(L[i], l[i]);
      cr[i] = min(R[i], r[i]);
      if (cl[i] > cr[i]) return false;
    }
    debug(l);
    debug(r);
    debug(L);
    debug(R);
    if (print) {
      ans[1] = cl[1];
      int le = ans[1] - mid;
      int ri = ans[1] + mid;
      for (int i = 2; i <= n; ++i) {
        ans[i] = max(cl[i], le);
      }
      debug(cl);
      debug(cr);
      for (int i = 1; i <= n; ++i) {
        if (i > 1) cout << " ";
        cout << ans[i];
      }
      cout << endl;
    }
    return true;
  };
  int le = 0, ri = 1e9;
  while (le <= ri) {
    int mid = le | (ri - le) >> 1;
    if (check(mid, 0)) ri = mid - 1;
    else le = mid + 1;
  }
  
  cout << ri + 1 << endl;
  check(ri + 1, b);
  //Read the stuff at the bottom
}
signed  main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout<<fixed<<setprecision(20);
  int T = 1;
  cin >> T >> b;
  for (int ti = 1; ti <= T; ++ti) {
    task();
  }
  return 0;
}

