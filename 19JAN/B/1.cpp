#include <bits/stdc++.h>
using namespace  std;
int n; 
int a[101], b[101], g[101];

int simulation(int guess_init_pos) {

    int pos[4] = {}, score = 0;
    pos[guess_init_pos] = 1; //* = 1, empty = 0  <=>pos[1][0] represents pop1[0]

    for (int i = 1; i <= n; ++i) {
      swap(pos[a[i]], pos[b[i]]);
      score = score + (pos[g[i]] == 1);  
    }

    return score;      
}
int main() {
    
    freopen("shell.in", "r", stdin);  

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i] >> g[i];
    }  

    int max_score = 0;
    for (int i = 1; i <= 3 ;++i) {
        max_score = max(max_score, simulation(i));
    }

     
    freopen("shell.out", "w", stdout);
    cout << max_score << endl;

     
}
