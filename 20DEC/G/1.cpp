#include <bits/stdc++.h>

using namespace std;



const int maxN = 1e3+5;

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

void testIO(string s){

    freopen(("G:\\C++\\SynologyDrive\\"+s+"\\test.in").c_str(),"r",stdin);

    return;

}

 int vis[maxN][maxN],vis2[maxN][maxN];

char grid[maxN][maxN];

bool ans[maxN][maxN];

int f[maxN][maxN];

int g[maxN][maxN];

int dx[] = {1,-1,0,0};

int dy[] = {0,0,1,-1};

int N,D;



struct pt{

    int x,y,t; //t = amount of hours elapsed

    pt(){};

    pt(int x, int y, int t){

        this -> x = x;

        this -> y = y;

        this -> t = t;

    }

};

queue<pt>Q;

struct cmp {

  bool operator () (const pt &a, const pt &b ) {

    return (a.t < b.t); 

  }

};

priority_queue<pt, vector<pt>, cmp> Q2;





void bfs(){



    while(!Q.empty()){

        pt c = Q.front(); Q.pop();



        int x = c.x; int y = c.y; int z = c.t;

        debug(x, y, z, f[x + z/D][y], D);

        

        if (f[x + z / D][y] < z /D + 1) continue;

        vis[x][y] = z;

        for(int k = 0; k < 4; ++k){

            int x1 = x + dx[k];

            int y1 = y + dy[k];

            if(x1 >= 1 && x1 <= N && y1 >= 1 && y1 <= N) 

            if (vis[x1][y1] == -1 && f[x1 + z / D][y1] >= z / D + 1) {

                vis[x1][y1] = z;

                Q.push(pt(x1,y1,z+1));

            }



        }

    }

    return;

}

void bfs2(){



    while(!Q2.empty()){

        pt c = Q2.top(); Q2.pop();

        int x = c.x; int y = c.y; int z = c.t;

        debug(x, y, z, f[x + z/D][y], D);

        if (vis2[x][y] > z) continue;

        if (z == 0) continue;

        for(int k = 0; k < 4; ++k){

            int x1 = x + dx[k];

            int y1 = y + dy[k];

            if(x1 >= 1 && x1 <= N && y1 >= 1 && y1 <= N) 

            if (vis2[x1][y1] < z - 1 && grid[x1][y1] != '#') {

                vis2[x1][y1] = z - 1;

                Q2.push(pt(x1,y1,z-1));

            }



        }

    }

    return;

}



inline int minimum(int a, int b, int c, int d){

    return min(a,min(b,min(c,d)));

}



int main(){

    ios_base::sync_with_stdio(false);

    cin.tie(0);

   // testIO("A");

    cin >> N >> D;

    for(int i = 1; i <= N; ++i){

        for(int j = 1; j <= N; ++j){

            cin >> grid[i][j];

        }

    }

    for(int i = 1; i <= N; ++i){

        for(int j = 1; j <= N; ++j){

            if(grid[i][j] == '#')f[i][j] = 0;

            else f[i][j] = minimum(f[i-2][j],f[i-1][j],f[i-1][j-1],f[i-1][j+1]) + 1;

        }

    }

    for(int i = 1; i <= N; ++i){

        for(int j = 1; j <= N; ++j){

          vis[i][j] = vis2[i][j] = -1;

        }

      }

      

    for(int i = 1; i <= N; ++i){

        for(int j = 1; j <= N; ++j){

            if(grid[i][j] == 'S'){

                  

                  Q.push(pt(i,j,0));

                }

        }

    }

    bfs();

    //fill in places where there could have been robots

    for(int i = 1; i <= N; ++i){

        for(int j = 1; j <= N; ++j){

            if(vis[i][j] == -1)continue;

            vis2[i][j] = vis[i][j] / D;

            Q2.push(pt{i,j,vis[i][j] / D});

        }

    }

    bfs2();

    int res = 0;

    for(int i = 1; i <= N; ++i){

        for(int j = 1; j <= N; ++j){

            if(vis2[i][j] != -1){

              ++res;

              debug(i, j);

            }

        }

    }

    cout << res << endl;

    return 0;

}


