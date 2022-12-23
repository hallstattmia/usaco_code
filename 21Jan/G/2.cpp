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
struct node {
  int pos, dis, label;
  node(int pos, int dis, int label) {
    this->pos = pos; this->dis = dis; this->label = label;
  }
  bool operator < (const node&x) const {
    return x.dis < dis;
  }
};
void task() {
  cin >> n >> nk;
  vector<int> a(n);
  re(n) cin >> a[i], a[i]--;
  vector<vector<int>> p(nk, vector<int>(nk));
  for (int i = 0; i < nk; ++i) {
    cin >> str;
    for (int j = 0; j < nk; ++j) { 
      p[i][j] = str[j] - '0';
    }
  }
  
  vector<int> dis(n, 1e9);
  dis[0] = 0;
  priority_queue<node> q;
  q.push((node){0, 0, 0});
  q.push((node){0, 0, 1});
  vector<set<int>> L(nk), R(nk);
  for (int i = 0; i < n; ++i) {
    L[a[i]].insert(i);
    R[a[i]].insert(i);
  } 
  
  while (!q.empty()) {
    debug(dis);
    int x = q.top().pos, d = q.top().dis, label = q.top().label;
    q.pop();
    if (label == 0) {
      for (int i = 0; i < nk; ++i) if (p[a[x]][i]) {
        while (L[i].size()) {
          auto it = L[i].begin();
          int y  = *it;         debug(x, y, d,label);
          if (y < x) {
            dis[y] = min(dis[y] , d - y);
            L[i].erase(it);
            q.push(node{y, dis[y] + y, 0});
            q.push(node{y, dis[y] - y, 1});
          } else {
            break;
          }
        }
      }
    }
    if (label == 1) {
      for (int i = 0; i < nk; ++i) if (p[a[x]][i]){
        while (R[i].size()) {
          auto it = --R[i].end();
          int y  = *it;            debug(x, y, d,label);
          if (y > x) {
            dis[y] = min(dis[y] , d + y);
            R[i].erase(it);
            q.push(node{y, dis[y] + y, 0});
            q.push(node{y, dis[y] - y, 1});
          } else {
            break;
          }
        }
      }
    }
  }

  debug(dis);
  cout << dis[n - 1] << endl;       
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
