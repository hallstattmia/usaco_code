#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXN 100002

using ll = long long;

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


int N,M,R;
vector<int> r, c;

struct storeInfo{
    int q;
    int p;
};
storeInfo store[MAXN];

bool cmp(int a, int b){
    return a>b;
}
bool cmpStruct(storeInfo a, storeInfo b){
    return a.p>b.p;
}

//ll shopBuy(int index){
    //ll prod=0;
    //ll price=0;
    //for(int a=0; a<=index; a++) prod+=c[a];
    //for(int b=0; b<M; b++){
        //if (prod<=store[b].q){
            //price += prod * store[b].p;
            //break;
        //}
        //price += store[b].q * store[b].p;
        //prod -= store[b].q;
    //}
    //return price;
//}

//ll rentOut(int index){
    //ll rent=0;
    //int num = N-index-1;
    //for(int i=0; i<num; i++) rent+=r[i];
    //return rent;
//}

int main(){
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);

    cin>>N>>M>>R;
    r.resize(R);
    c.resize(N);
    for(int i=0; i<N; i++){
      int x; cin>>x;
      c.push_back(x);
    }
    for(int i=0; i<M; i++) cin>>store[i].q>>store[i].p;
    for(int i=0; i<R; i++){
      int y; cin>>y;
      r.push_back(y);
    }

    sort(c.begin(), c.end(), cmp);
    sort(store, store+M, cmpStruct);
    sort(r.begin(), r.end(), cmp);
    vector<long long> sell(N + 1), rent(N + 1);
    int j = -1, remain = 0; //sell who
    for (int i = 1; i <= N; ++i) {
       sell[i] = sell[i - 1];
       int prod = c[i - 1]; 
       while (prod && j < M) {
         while (j < M && remain == 0) {
           ++j;
           if (j == M) break; // j == M not exist
           remain = store[j].q;
         }
         if (j == M) break;
         ll sell_number = min(prod, remain);
         prod -= sell_number;
         remain -= sell_number;
         sell[i] += sell_number * store[j].p;
       }
    }
    j = -1;
    for (int i = 1; i <= N; ++i) {
       rent[i] = rent[i - 1];
       ++j;
       if (j >= R) continue;
       rent[i] += r[j];
    }   

    ll maxp=0, temp;
    ll inStores, inRent;
    for(int i=0; i<=N; i++){ // i cows sell 
        if (i<=M && N-i<=R){
            //inStores = shopBuy(i);
            //inRent = rentOut(i);
            inStores = sell[i];
            inRent = rent[N - i];
            temp = inStores + inRent;            
            debug(inStores, inRent);
            if (temp<maxp) break;
            maxp = max(maxp,temp);
         }
    }
    
    cout<<maxp<<endl;
}           
