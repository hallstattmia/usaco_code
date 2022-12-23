#include <bits/stdc++.h>
using namespace std;
 
void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}
 
const int MX = 2e5+5;
 
int N,M;
 
int par[MX],cnt[MX],sz[MX];
vector<int> adj[MX];
queue<int> q; 
int find(int x) {
  if (x == par[x]) return x;
  return par[x] = find(par[x]);
}

void merge(int a, int b) {
  a = find(a), b = find(b); 
  if (a == b) return;
  if (sz[a] < sz[b]) swap(a, b);
  sz[a] += sz[b];
  par[b] = a;
  adj[a].insert(end(adj[a]),begin(adj[b]),end(adj[b])); 
  adj[b].clear();
  if (adj[a].size() > 1) q.push(a);
}
 
int main() { 
  setIO("fcolor");
  cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    int a,b; cin >> a >> b;
    adj[a].push_back(b);
  }
  for (int i = 1; i <= N; ++i) {
    par[i] = i;    sz[i] = 1;
    if (adj[i].size() > 1) q.push(i);
  }
  while (q.size()) {
    int x = q.front(); if (adj[x].size() <= 1) { q.pop(); continue; }
    int a = adj[x].back(); adj[x].pop_back();
    merge(a,adj[x].back());
  }
  int co = 0;
  for (int i = 1; i <= N; ++i) {
    if (!cnt[find(i)]) cnt[find(i)] = ++co;
    cout << cnt[find(i)] << "\n";
  }
}
