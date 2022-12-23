#include <bits/stdc++.h>
#pragma GCC optimize(3)
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

vector<int> guess;
vector<int> out;
int ans, cnt, ans2;
int cost[26][26];
vector<vector<int>> dp2;
vector<int> dp3;
inline int shfit_z(int z){
  if (dp3[z] != -1) return dp3[z];
  int x = z, cnt = -1;
  while (x) x >>= 1, cnt++;
  dp3[z] = cnt;
  debug(z, cnt);
  return dp3[z];
}
int calc_cost(int y, int x) {
  if (dp2[y][x] != -1) return dp2[y][x];
  if (x == 0) return 0;
  int z = x&(-x);
  debug(y, x);
  dp2[y][x] = calc_cost(y, x - z) + cost[y][shfit_z(z)];
  return dp2[y][x] ;
}
void task() {
  cin >> str;
  n = str.size();
  vector<int> id(256, -1);
  int now_id = 0;

  for (int i = 1; i < n; ++i) {     //'a'..'z' - 'mildre' ==>0 .. 19
     if (id[str[i-1] - 'a'] == -1) id[str[i-1] - 'a'] = now_id++;
     if (id[str[i] - 'a'] == -1) id[str[i] - 'a'] = now_id++;
     cost[id[str[i-1] - 'a']][id[str[i] - 'a']]++;
  }

  m = now_id;
  vector<int> dp(1<<m, 1e9);
  dp2 = vector<vector<int>>(m, vector<int>(1 << m, -1));
  dp3 = vector<int>(1 << m, -1);
  dp[0] = 0;
  for (int i = 0; i < (1 << m); ++i) {
  
     for (int j = 0; j < m; ++j) {   //dp[i] + j == > dp[i + j]
       
       if ((i >> j)&1) continue;
       dp[i + (1 << j)] = min(dp[i + (1 << j)], dp[i] + calc_cost(j, i + (1 << j)));
       //debug(i, dp[i], dp[i + ( 1 << j)],  j, calc_cost(j, i));
     }
  }
  cout << dp[(1 << m) - 1] + 1 << endl;
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

//O(2^m * m)
