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
bool cmp(pair<int, int> p1, pair<int ,int> p2) {
  return p1.second < p2.second;
}
vector<vector<int>> prefix;
int query(int x1, int x2, int y1, int y2) {
  return prefix[x2 + 1][y2 + 1] - prefix[x1][y2 + 1] 
  - prefix[x2 + 1][y1] + prefix[x1][y1];
  
}
void task() {
  cin >> n;
  vector<pair<int, int>> p(n);
  for (int i = 0; i < n; ++i) cin >> p[i].first >> p[i].second; 
  sort(p.begin(), p.end());
  for (int i = 0; i < n; ++i) p[i].first = i;
  sort(p.begin(), p.end(), cmp);
  for (int i = 0; i < n; ++i) p[i].second = i;  
  prefix = vector<vector<int>>(n + 1, vector<int> (n + 1, 0));
  for (int i = 0; i < n; ++i)
    prefix[p[i].first + 1][p[i].second + 1] += 1;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      prefix[i + 1][j + 1] += prefix[i][j + 1] + prefix[i + 1][j] - prefix[i][j]; 
    }
  long long ans = 1;  
  sort(p.begin(), p.end());
  for (int i = 0; i < n; ++i)   //p[i].first = i
    for (int j = i; j < n; ++j) { //p[j].first = j
      int yleft = min(p[i].second, p[j].second);
      int yright = max(p[i].second, p[j].second);
      int left_num  = query(i, j, 0, yleft);
      int right_num = query(i, j, yright, n - 1);
      ans += left_num * right_num;
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

/* stuff you should look for
  * int overflow, array bounds
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
  * write down
*/
