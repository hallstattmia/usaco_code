#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxN = 1e5+5;

int pro[maxN]; //proficiency
int a[maxN]; //dummy
int child[maxN]; //点i的儿子数量
int id[maxN]; //第i头牛被按dfs序标为了id[i]号牛
int rev[maxN]; //id的反函数
int ans[maxN];
int order[maxN];
int tree[maxN<<2];
vector<vector<int>> d;
vector<vector<int>> adj;
map<int,int> m;
int cnt;
int N;

#define lc (p<<1)
#define rc (p<<1)+1

void pushUp(int p){
    tree[p] = tree[lc] + tree[rc];
    return;
}

void update(int p, int l, int r, int a, int b, int val){
    if(a > r || b < l)return;
    if(a <= l && b <= r){
        tree[p] = val;
        return;
    }
    int mid = (l+r)>>1;
    update(lc,l,mid,a,b,val);
    update(rc,mid+1,r,a,b,val);
    pushUp(p);
    return;
}

int query(int p, int l, int r, int a, int b){
    if(a > r || b < l)return 0;
    if(a <= l && r <= b)return tree[p];
    int mid = (l+r)>>1;
    return query(lc,l,mid,a,b) + query(rc,mid+1,r,a,b);
}

#undef lc
#undef rc

void dfs1(int x){
    for(int i = 0; i < adj[x].size(); ++i){
        dfs1(adj[x][i]);
        child[x]++;
        child[x] += child[adj[x][i]];
    }
    return;
}

void dfs2(int x){
    id[x] = ++cnt;
    for(int i = 0; i < d[x].size(); ++i){
        dfs2(d[x][i]);
    }
    return;
}

void setIO(string s){
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
    return;
}

void testIO(){
    freopen("G:\\C++\\SynologyDrive\\PromotionCounting\\test.in","r",stdin);
    return;
}

signed main(){
    //setIO("promote");
    //testIO();
    cin >> N;
    for(int i = 1; i <= N; ++i)cin >> pro[i];
    for(int i = 0; i <= maxN; ++i)d.push_back(vector<int>());
    for(int i = 0; i <= maxN; ++i)adj.push_back(vector<int>());
    for(int i = 2; i <= N; ++i){
        int fa;
        cin >> fa;
        d[fa].push_back(i);
    }
    dfs2(1); //id
    for(int i = 1; i <= N; ++i)rev[id[i]] = i;
    for(int i = 1; i <= N; ++i){
        for(int j = 0; j < d[i].size(); ++j){
            adj[id[i]].push_back(id[d[i][j]]);
        }
    }

    //离散化能力值
    for(int i = 1; i <= N; ++i)a[i] = pro[i];
    sort(a+1,a+1+N);
    for(int i = 1; i <= N; ++i){
        m.insert(pair<int,int>(a[i],i));
    }

    //dfs
    dfs1(1); //每个点儿子的数量
    for(int i = 1; i <= N; ++i){
        a[id[i]] = m[pro[i]]; //第i头牛的能力值是pro[i]
    }
    for(int i = 1; i <= N; ++i){
        order[a[i]] = i;//有能力值i的牛是第order[i]头牛
    }

    //线段树
    //从能力值最低的牛开始 (order数组)
    for(int i = 1; i <= N; ++i){
        update(1,1,N,order[i],order[i],1);
        if(child[order[i]] == 0){ans[rev[order[i]]] = 0;continue;}
        ans[rev[order[i]]] = child[order[i]] - query(1,1,N,order[i]+1,order[i]+child[order[i]]);
    }
    for(int i = 1; i <= N; ++i)cout << ans[i] << endl;
    return 0;
}
