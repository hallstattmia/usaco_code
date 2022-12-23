#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>

using namespace std;
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

int main() {
  int n;
  cin >> n;
  
  string a;
  cin >> a;
  long long ans = 0;
  
  
  
  //for (int L = 0; L < n; ++L)
    //for (int R = L; R < n; ++R) {
      
      //if (R - L + 1 < 3) continue;
      //int cnt = 0;
      //for (int i = L; i <= R; ++i) {
         //if (a[i] == 'H') cnt++; 
      //}
      
      ////H:cnt G:(R-L+1) - cnt
      //if (cnt == 1 || (R-L+1) - cnt == 1) ans++;
  //}
  
  for (int x = 0; x < n; ++x)  {
      if (a[x] == 'H') {
          int L = x, R = x;
          while (L - 1 >= 0 && a[L - 1] == 'G') L--;
          while (R + 1 < n && a[R + 1] == 'G') R++;
          //for (int i = L; i <= x; ++i)
            //for (int j = x; j <= R; ++j) {
                //if (j - i + 1 >= 3) {
                    //ans++;
                //}
          for (int i = L; i <= x; ++i) {
               int cnt = R - max(i + 2, x) + 1;
               ans += max(0, cnt);
            }  
      }
  }
  

  for (int x = 0; x < n; ++x)  {
      if (a[x] == 'G') {
          int L = x, R = x;
          while (L - 1 >= 0 && a[L - 1] == 'H') L--;
          while (R + 1 < n && a[R + 1] == 'H') R++;
        
          for (int i = L; i <= x; ++i) {
            int cnt = R - max(i + 2, x) + 1;
            ans += max(0, cnt);
          }  
      }
  }
  
  //for (int L = 0; L < n; ++L) {
    //int cnt = 0;
    //for (int R = L; R < n; ++R) {
      //if (a[R] == 'H') ++cnt;
      //if (R - L + 1 < 3) continue;
      
      ////H:cnt G:(R-L+1) - cnt
      //if (cnt == 1 || (R-L+1) - cnt == 1) ans++;
    //}
  //}      
      
      
  //for (int L = 0; L < n; ++L)
    //for (int R = L; R < n; ++R) {
      //if (R - L + 1 < 3) continue;
      //int H = 0, G = 0;
      //for (int i = L; i <= R; ++i) {
        //if (a[i] == 'H') ++H;
        //else ++G;
      //}
      //if (H == 1 || G == 1) ans++;
      //if (H == 1 && G == R - L) ans++;
      //if (G == 1 && H == R - L) ans++;
    //}

  //for (int L = 0; L < n; ++L) {
    //int H = 0, G = 0; 
    //for (int R = L; R < n; ++R) {
      //if (a[R] == 'H') ++H;
      //else ++G;
      //if (R - L + 1 < 3) continue;

      //if (H == 1 || G == 1) ans++;
      ////if (H == 1 && G == R - L) ans++;
      ////if (G == 1 && H == R - L) ans++;
    //}  
  //} 
  //for (int R = 0; R < n; ++R) {
    //int H = 0, G = 0;
    //for (int L = R; L >= 0; --L) {
      //if (a[L] == 'H') ++H;
      //else ++G;
      //if (R - L + 1 < 3) continue;
      //if (H == 1 || G == 1) ans++;
      //else {
        //if (H >= 2 && G >= 2) break;
      
    //}
   
  //}
  // HHHHG // HGHGG
  //int lastG = -1, lastH = -1, lastlastH = -1, lastlastG = -1;
  //for (int R = 0; R < n; ++R) {
    
    //if (a[R] == 'G') {
      //lastlastG = lastG; lastG = R;
      //if (lastH != -1) 
        //ans += (lastH - lastlastH);
      //if (lastG != -1) 
        //ans += (lastG - lastlastG - 1);
    //} 
    //else {
      //lastlastH = lastH; lastH = R;
      //if (lastH != -1) 
        //ans += (lastH - lastlastH - 1);
      //if (lastG != -1) 
        //ans += (lastG - lastlastG);      
    //}
    //debug(lastH, lastlastH, lastfG, lastlastG, ans);
  //}  
    //for (int i = 0; i < n - 1; ++i) ans -= 2 * (a[i] != a[i + 1]);  
    
      
  //vector<int> last(n);
  //for (int R = 0; R < n; ++R) {
    //last[R] = R;
    //if (R - 1 >= 0 && a[R] == a[R - 1]) last[R] = last[R - 1];
    //debug(last[R], R);
    //if (last[R] == R) {
      //if (R) ans += R - 1 - last[R - 1];
    //} else {
      ////GGH
      //if (R >= 2) {
        //int j = last[R - 2];
        //ans++;
        //if (j > 0 && a[j] != a[j - 1]) ans += j - last[j - 1] ;
      //}
    //}
  //}     
   
  cout << ans << "\n";
}
    
