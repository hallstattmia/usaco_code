#pragma GCC optimize ("O3")#include <bits/stdc++.h>using namespace  std;void debug_out() { cerr  << endl; }#ifdef __APPLE__#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: " << __VA_ARGS__, debug_out()#else#define debug(...) 42#endif#define sz(x) (int)(x).size()#define mp make_pair#define pb push_back#define f first#define s second#define lb lower_bound#define ub upper_bound#define all(x) x.begin(), x.end()#define ins insertconst int maxn = 1e2 + 10;const int md = 1e9 + 7;int T;string str;int x, y, n, m;vector<pair<int, int> > e[maxn][maxn];int open[maxn][maxn]; //0 : not open, 1:open, 2 : walkconst int dir[4][2] = {{0, 1}, {0, -1},{1, 0},{-1, 0} };bool check(int x, int y) {
	if (open[x][y] != 1) return false; // 1: open	for (int k = 0; k < 4; ++k) {
		int x1 = x + dir[k][0], y1 = y + dir[k][1];		if (x1 > 0 && x1 <= n && y1 > 0 && y1 <= n && open[x1][y1] == 2) return true;
	} 	return false;
}void task() {	cin >> n >> m;	for (int i = 0; i < m; ++i) {		int x, y, x2, y2;
		cin >> x >> y >> x2 >> y2;		e[x][y].push_back(make_pair(x2, y2));
	}	int ans = 1;	/*open[1][1] = 2;	for (auto p : e[1][1]) {	 if (open[p.first][p.second] == 0) {			open[p.first][p.second] = 1;			ans++;	 }  }	while (1) {	  int ok = 0;
		for (int i = 1; i <= n; ++i) 			for (int j = 1; j <= n; ++j) {
				 if (open[i][j] == 2) {
					 for (int k = 0; k < 4; ++k) {
						 int x = i + dir[k][0], y = j + dir[k][1];						 if (x > 0 && x <= n & y > 0 && y <= n && open[x][y] == 1) {
							 open[x][y] = 2; ok = 1;							 for (auto p : e[x][y]) {								 if (open[p.first][p.second] == 0) {
									  open[p.first][p.second] = 1;									  ans++;
								 }					 		 }
						 } 
					 }
				 }
			}		if (!ok) break;		 
	}    */	queue<pair<int, int>> q;	open[1][1] = 2;  //  2:walk -> use all keys in room.	q.push(make_pair(1, 1));	while (!q.empty()) {
		int i = q.front().first, j = q.front().second;  q.pop();		for (auto p : e[i][j]) {			 if (open[p.first][p.second] == 0) {					open[p.first][p.second] = 1;					if (check(p.first, p.second)) {						open[p.first][p.second] = 2;
						q.push(make_pair(p.first, p.second));
					}					ans++;			 }		}		for (int k = 0; k < 4; ++k) {			 int x = i + dir[k][0], y = j + dir[k][1];			 if (x > 0 && x <= n & y > 0 && y <= n) {	 			   if (check(x, y)) {					 open[x][y] = 2;					 q.push(make_pair(x, y));				 }			 }		}
	}	//bruce force : n^4 + m   Silver	//bfs : n^2 + m  Gold	// (x,y)can be walked <->1) (x,y):open 2)dir = 0, 1, 2,3 room open	 	cout << ans << endl;}int main() {  ios_base::sync_with_stdio(false);  cin.tie(NULL);  T = 1;  while (T--){    task();  }  return 0;}