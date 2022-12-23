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
vector<vector<int>> e(51);
vector<int> fa(51), last_seen(51), cnt(51);
int ti, last_ti;
void dfs(int u) {
  cnt[u] = ++ti;
  for (auto v : e[u]) {
    dfs(v);
  }
}
    
void task() {
  cin >> n >> m;
  bool ok = true;
  

  for (int i = 0; i <= n; ++i) {
    last_seen[i] = -1;
  }

  
  auto add =[&](int x, int y) {
    if (fa[y] != -1) {
      if (fa[y] != x) {
        ok = false;
      }
      if (cnt[y] < last_ti) {
        ok = false;
      }

      last_ti = cnt[y];
    } else {
      e[x].pb(y);
      fa[y] = x;
    }
  };
  vector<vector<pii>> edge(m);
  for (int t = 0; t < m; ++t) {    
    int k; cin >> k;
    stack<int> sta;
    sta.push(0);

    while(k--) {
      int c; cin >> c;
      if (!ok) continue;
      
      if (last_seen[c] == t + 1 && sta.top() == c) {
        sta.pop();
      } else {
        if (last_seen[c] == -1 || last_seen[c] == t){
          last_seen[c] = t + 1;
          edge[t].pb({sta.top(), c});
          sta.push(c);
        }
        else {
          ok = false;
        }
      }
    }
    
    ok &= (sta.size() <= 1);  
  }
  
  for (int i = 1; i < m; ++i)  {
      for (int k = 0;  k <= n; ++k) fa[k] = -1, e[k].clear(); 
      for (auto p : edge[i-1]) add(p.fi, p.se);
      ti = last_ti = 0;
      dfs(0);
      for (auto p : edge[i]) add(p.fi, p.se);
      if (!ok) break;
  }
  
  if (ok) ps("YES");
  else ps("NO");        
  //Read the stuff at the bottom
}
signed  main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout<<fixed<<setprecision(20);
  int T = 1;
  cin >> T;
  for (int ti = 1; ti <= T; ++ti) {
    task();
  }
  return 0;
}

