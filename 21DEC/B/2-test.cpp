#include <bits/stdc++.h>
using namespace  std;

int main() {
    int n;
    cin >> n;
    vector<int> t(n), s(n);
    for (int i = 0; i < n; ++i) cin >> t[i];
    for (int i = 0; i < n; ++i) cin >> s[i];
    int ans = 0;
    for (int i = 0 ; i < n ; ++i) {
        if (s[i] < t[i]) {
            while (s[i] < t[i]) {
                ++ans;
                for (int j = i; j < n; ++j) {
                    if (s[j] < t[j]) ++s[j];
                    else break;
                }
            }
        }
    
        
        if (s[i] > t[i]) {
            while (s[i] > t[i]) {
                ++ans;
                for (int j = i; j < n; ++j) {
                    if (s[j] > t[j]) --s[j];
                    else break;
                }
            }
        }
        
    }
    cout << ans << endl;
    
    
    
}
