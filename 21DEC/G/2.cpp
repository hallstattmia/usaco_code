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
void bruce() {
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  //x = 3.5 a = 5 2 6 1
  for (int x = 0; x <= n; ++x) {
    int last = 0, L = 0, R = n + 1, ans = 0 ;
    for (int i = 0; i < n; ++i) {
      if (a[i] < L || a[i] >= R) continue;
      if (x < a[i]) last = 1, R = a[i];
      else {
        L = a[i];
        if (last == 1) ++ans;
        last = 0;
      }
    }
    cout << ans << "\n";
  }
}  
void task() {
  cin >> n;
  vi a(n);
  vi pos(n + 2);
  pos[0] = pos[n + 1] = -1;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    pos[a[i]] = i;
  }
  set<int> tr;
  tr.insert(0);
  tr.insert(n + 1);
  vi delta(n + 1);
  for (int i = 0;i < n; ++i) {
    auto R = *tr.lower_bound(a[i]);
    auto L = *(--tr.lower_bound(a[i]));
    int x;
    if (pos[L] > pos[R]) x = L;
    else x = R; 
    if (x <= n && x > a[i]) {
      delta[a[i]]++;
      delta[x]--;
    }
    tr.insert(a[i]);
  }
  for (int i = 1; i <= n; ++i) 
    delta[i] += delta[i-1];
  for (int i = 0; i <= n; ++i)
    cout << delta[i] << "\n";
      
    
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

