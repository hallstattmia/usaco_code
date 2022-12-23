#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    //vector<vector<bool>> edges(n, vector<bool>(n));     //int edges[n][n];
    //vector<bool> edges[n];
    //for (int i = 0; i < m; ++i) {
        //int x, y;
        //cin >> x  >> y;
        //edges[x][y] = true;
    //}
    

    
    
    vector<vector<int>> edges(n);    //vector<int> edges[n];  //0, 1
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x  >> y;
        edges[x].push_back(y);
    }
    int x = 1;
    for (auto y : edges[x]) {  //O(edges[x].size())
        cout << x << " "<<y << endl;
    }
        
    
}
