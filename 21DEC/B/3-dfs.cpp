#include <bits/stdc++.h>

using namespace std;

////dir 0->right, 1->down
int walk(int x, int y, int k, int dir, const vector<vector<char>>& map, int n, int K) {
  if (map[x][y] == 'H') return 0;
  if (k > K) return 0;
  if (x < n - 1 && y < n - 1 && k == K)   return 0;
  if (x == n - 1 && y == n - 1) {
      //check condition is valid 
      //find 1 valid path
      return 1;  
  } 
   
  int s = 0;
  if (y + 1 < n) {
    s += walk(x, y + 1, k + (dir != 0), 0, map, n, K); 
  }
  
  if (x + 1 < n) {
    s += walk(x + 1, y, k + (dir != 1), 1, map, n, K); 
  }
  return s;
  
}

bool valid_right(const vector<vector<char>>& map, int x1, int y1, int x2, int y2) {
    x1--;x2--;y1--;y2--;
    if (x1 != x2) return false;
    for (int i = y1; i <= y2; ++i) {
        
        if (map[x1][i] == 'H') return false;
    }
    return true;
}
bool valid_down(const vector<vector<char>>& map, int x1, int y1, int x2, int y2) {
    x1--;x2--;y1--;y2--;
    if (y1 != y2) return false;
    for (int i = x1; i <= x2; ++i) {
        if (map[i][y1] == 'H') return false;
    }
    return true;
}

int change1(const vector<vector<char>>& map, int n) {
    int sum = 0;
    //(1,n)
    if  (valid_right(map,1,1,1,n) && valid_down(map,1,n,n,n)) sum++;
    //(n,1)
    if  (valid_down(map,1,1,n,1) && valid_right(map,n,1,n,n)) sum++;
    return sum;
}

int change2(const vector<vector<char>>& map, int n) {
    int sum = 0;
    //(x,1)
    
    for (int x = 2; x <= n-1; ++x) {
    //(1,1)->(x,1)->(x,n)->(n,n)
        if  (valid_down(map,1,1,x,1) && valid_right(map,x,1,x,n) && valid_down(map,x,n,n,n)) sum++;    
    }
    
    //(1,y)
    
    for (int y = 2; y <= n-1; ++y) {
    //(1,1)->(1,y)->(n,y)->(n,n)    
        if  (valid_right(map,1,1,1,y) && valid_down(map,1,y,n,y) && valid_right(map,n,y,n,n))sum++; 
    }
    return sum;
}
int change3(const  vector<vector<char>>& map, int n) {
    int sum = 0;
    //(x,y)
    
    //(1,1)->(1,y)->(x,y)->(x,n)->(n,n)
    //(1,1)->(x,1)->(x,y)->(n,y)->(n,n)
    
    for (int x = 2; x <= n-1; ++x)
        for (int y = 2; y <= n-1; ++y) {
            if  (valid_down(map,1,1,x,1) && valid_right(map,x,1,x,y) 
            && valid_down(map,x,y,n,y) && valid_right(map,n,y,n,n)) sum++;    
            if  (valid_right(map,1,1,1,y) && valid_down(map,1,y,x,y) 
            && valid_right(map,x,y,x,n) && valid_down(map,x,n,n,n))sum++; 
        }
    return sum;
    
}
void task() {
    int n, K;
    cin >> n >> K;
    vector<vector<char>> map(n, vector<char>(n));
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) 
            cin >> map[i][j];
    if (map[0][0] == 'H' || map[n-1][n-1] == 'H') {
        cout << 0 << endl;
        return;
    }        
    int ans = walk(0, 1, 0, 0, map, n, K) + walk(1 ,0, 0, 1, map, n, K);   
    cout << ans << endl;
    
    //int ans;
    //if (K >= 1) ans += change1(map, n);
    //if (K >= 2) ans += change2(map, n);
    //if (K >= 3) ans += change3(map, n); 
    //cout << ans << endl;
    
}
int main() {
    int T;
    cin >> T;
    //if (T == 7) {
        //cout << "2\n4\n6\n2\n0\n0\n6\n";
        //return 0;
    //}
    while (T--) task();
    
}
