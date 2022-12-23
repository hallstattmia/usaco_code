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
template<class T> struct Seg { // comb(ID,b) = b
  const T ID = 0; T comb(T a, T b) { return a+b; }
  int n, h; vector<T> seg, d;

  void init(int _n) { n = _n; while((1<<h)<2 * n) ++h;seg.assign(2*n,ID); d.assign(n, ID);}
  void apply(int p, T value, long long len) {
    seg[p] += value * len;
    if (p < n) d[p] += value;
  }
  void build(int p) {
    int len = 1;
    while (p > 1) p >>= 1, len <<= 1, seg[p] = comb(seg[p<<1], seg[p<<1|1]) + d[p] * len; }    //+d[p]?

  void push(int p) {
    for (int s = h; s > 0; --s) {
      int i = p >> s;
      if (d[i] != 0) {
        apply(i<<1, d[i], 1<<(s-1));
        apply(i<<1|1, d[i], 1<<(s-1));
        d[i] = 0;
      }
    }     
  }

  void inc(int l, int r, T value) {
    l += n, r += n + 1;
    int l0 = l, r0 = r, len = 1;
    for (; l < r; l >>= 1, r >>= 1) {
      debug(l, r, value, len);
      if (l&1) apply(l++, value, len);
      if (r&1) apply(--r, value, len);
      len <<= 1;
    }
    build(l0);
    build(r0 - 1);
  }

  T query(int l, int r) { // sum on interval [l, r]
    T ra = ID, rb = ID;
    l += n, r += n+1;
    push(l);
    push(r - 1);
    for (; l < r; l /= 2, r /= 2) {
      if (l&1) ra = comb(ra,seg[l++]);
      if (r&1) rb = comb(seg[--r],rb);
    }
    return comb(ra,rb);
  }

  

};

Seg<long long> st;


const int maxn = 1e6 + 10;

int n, m, nq, nk;
string str;

int  main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout<<fixed<<setprecision(20);
  cin >> n;
  vector<int> last(n + 1, 0);
  long long ans = 0;
  vector<int> a(n + 1);
  st.init(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    int l = last[a[i]] + 1;
    int r = i - 1;
    debug(l, r);
    ans += st.query(l, r);
    debug(ans);
    if (last[a[i]] != 0) st.inc(last[a[i]], last[a[i]], -1);
    st.inc(i, i, 1);
    last[a[i]] = i;
  } 
  cout << ans << endl;  
  return 0;
}

