#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("cbarn.in", "r",  stdin);       
    freopen("cbarn.out", "w", stdout);     
    
    int n;
    cin >> n;

    int r[n];
    for (int i = 0; i < n; i++)
    {
        cin >> r[i];
    }
    
    int d[n];
    for (int i = 0; i < n; ++i) d[i] = i; //enter room 0
    long long min_dis = 1e18;
    for (int door = 0; door < n; ++door) {
        for (int i = 0; i < n; ++i) {
            d[i] = i - door;
            if (d[i] < 0) d[i] += n;
        }
        long long dis = 0;
        //for (int i = 0; i < n; ++i)  cout << d[i] << " ";cout << endl;
        for (int i = 0; i < n; ++i) {
            dis += r[i] * d[i];
        }
        min_dis = min(dis, min_dis);
        //cout << door << " " << dis << endl;
    
    }
    cout << min_dis << endl;
            
    
}
