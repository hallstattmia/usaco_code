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



int n, m, stx , sty;
string str;
struct node{
  int bad, x, y, z;
};
node g[30][30];
const int dir[4][2] = {{-1,0}, {1, 0}, {0, -1}, {0, 1}};
vector<int> base3(10);
void solve(int z,node v, int &z1, bool &finish) {
  int  p[3][3] = {};
  for (int i = 0; i < 3; ++i) 
    for (int j = 0; j < 3; ++j) {
      int r = (z / base3[i * 3 + j] % 3);
      p[i][j] = r;
      debug(r);
    }  
  
  z1 = z;
  if (p[v.x][v.y] == 0) {
    z1 = z + base3[v.x * 3 + v.y] * v.z;
    debug(base3[v.x * 3 + v.y], v.x, v.y, v.z);
    p[v.x][v.y] = v.z;
  } 
  if (z1 == z) return;
  for (int i = 0; i < 3; ++i) {
    if (p[i][0] == 1 && p[i][1] == 2 && p[i][2] == 2) finish = true;
    if (p[i][0] == 2 && p[i][1] == 2 && p[i][2] == 1) finish = true;
    if (p[0][i] == 1 && p[1][i] == 2 && p[2][i] == 2) finish = true;
    if (p[0][i] == 2 && p[1][i] == 2 && p[2][i] == 1) finish = true;
  } 
  if (p[0][0] == 1 && p[1][1] == 2 && p[2][2] == 2) finish = true;
  if (p[0][0] == 2 && p[1][1] == 2 && p[2][2] == 1) finish = true;
  if (p[0][2] == 1 && p[1][1] == 2 && p[2][0] == 2) finish = true;
  if (p[0][2] == 2 && p[1][1] == 2 && p[2][0] == 1) finish = true;
}
int  main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout<<fixed<<setprecision(20);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> str;
    for (int j = 0; j < str.size(); j += 3) {
      if (str[j] == '#') {
         g[i][j / 3].bad = -1;
      }
      if (str[j] == 'B') {
        stx = i;
        sty = j / 3;
      }
      if (str[j] == 'M') {
        g[i][j / 3].x = str[j+1] - '1';
        g[i][j / 3].y = str[j+2] - '1'; 
        g[i][j / 3].z = 1;       
      }
      if (str[j] == 'O') {
        g[i][j / 3].x = str[j+1] - '1';
        g[i][j / 3].y = str[j+2] - '1'; 
        g[i][j / 3].z = 2;       
      }       
    }
  }
  
  queue<tuple<int, int, int>> q;
  q.push(make_tuple(stx, sty, 0));

  base3[0] = 1;
  for (int i = 1; i <= 9; ++i) base3[i] = base3[i - 1] * 3;
  vector<int> score(base3[9]);
  vector<vector<vector<bool>>> vis(n, vector<vector<bool>>(n, vector<bool>(base3[9])));
  int ans = 0;
  while (!q.empty()) {
    int x, y, z;
    tie(x, y, z) = q.front();
    q.pop();
    for (int i = 0; i < 4; ++i) {
      int x1 = x + dir[i][0];
      int y1 = y + dir[i][1];
      int z1 = 0;
      if (x1 < 0 || y1 < 0 || x1 >= n || y1 >= n || g[x1][y1].bad) continue;
      bool finish = false;
      solve(z, g[x1][y1], z1, finish);
      debug(x1, y1, z1, finish);
      if (!vis[x1][y1][z1]) {
        vis[x1][y1][z1] = 1;
        if (!finish) q.push(make_tuple(x1,y1,z1));
        else {
          if (!score[z1]) ans++;
          score[z1] = 1;
        }     
      }
    }
    
  }
  cout << ans << endl;
  return 0;
}

