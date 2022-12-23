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
struct Apple {
  int x, t, n;
  Apple(int _x, int _t, int _n) {
   x = _x, t = _t, n = _n;
  }
};
struct Cow {
  int l, r, n;
  Cow(int _l, int _r, int _n) {
   l = _l, r = _r, n = _n;
  }
};
class CowSet
{
public:
    CowSet(int l, int r, int n)
        : l(l), r(r), n(n)
    {
    }
    bool operator < (const CowSet& cowset) const
    {
        return this->r < cowset.r || (this->r == cowset.r && this->l < cowset.l);
    }
 
    int l, r, n;
};
void task() {
  ll n, m;
  cin >> n;
  
  vector<Apple> apples;
  vector<Cow> cows;
  for (int i = 0; i < n; ++i) {
    int q, t, x, n;
    cin >> q >> t >> x >> n;
    if (q == 1) {
      cows.push_back(Cow(x + t, x - t, n));
    } else {
      apples.push_back(Apple(x, t, n));
    }
  }
  sort(apples.begin(), apples.end(), 
    [](const Apple &a, const Apple &b){
      return a.x + a.t < b.x + b.t;
    }
  );
  
  sort(cows.begin(), cows.end(), 
    [](const Cow &a, const Cow &b){
      return a.l < b.l || (a.l == b.l && a.r < b.r);
    }
  );
  set<CowSet> tr;
  long long ans = 0;
  int i = 0;
  for (auto apple : apples) {
    while (i < cows.size() && cows[i].l <= apple.x + apple.t) {
      debug(cows[i].l, cows[i].r, cows[i].n);
      tr.insert(CowSet(cows[i].l, cows[i].r, cows[i].n));
      ++i;
    }
    debug(apple.x, apple.t, apple.n);
    int remain = apple.n;
    while (remain > 0) {
      //while (tr.size() && tr.begin()->r <  apple.x - apple.t) {
        //tr.erase(tr.begin());
      //}
      if (tr.size() == 0) break;
      auto it = tr.lower_bound(CowSet(-1e9, apple.x - apple.t, -1e9));
      if (it == tr.end()) break;
      int use = min(remain, it->n);
      auto cowset = *it;
      tr.erase(it);
      cowset.n -= use;
      if (cowset.n > 0) tr.insert(cowset);
      remain -= use;
      ans += use;
       
    }
  }
  cout << ans << endl;
   
  
      
    
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

