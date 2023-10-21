// ~BhupinderJ
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pii pair<int, int>
#define vvi vector<vector<int>>
const int N = 2e5;

vi edge[N+1];
vi dep(N+1, 0);
vi cnt(N+1, 0);
vvi par(N+1, vi(20, 0));

void dfs(int cv, int pv){
    dep[cv] = 1 + dep[pv];
    par[cv][0] = pv;
    for(int i=1 ; i<20 ; i++)
        par[cv][i] = par[par[cv][i-1]][i-1];
    for(int v : edge[cv]){
        if(v == pv) continue;
        dfs(v, cv);
    }
}
int _lca(int u, int v){
    if(dep[u] < dep[v])
        swap(u, v);
    int d = dep[u] - dep[v];
    for(int i=19 ; i>=0 ; i--){
        if((d>>i)&1) u = par[u][i];
    }
    if(u == v) return u;
    for(int i=19 ; i>=0 ; i--){
        if(par[u][i] != par[v][i]){
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}
void solve(int cv, int pv){
    for(int v : edge[cv]){
        if(v == pv) continue;
        solve(v, cv);

        cnt[cv] += cnt[v];
    }
}
signed main(){
    int n, q; cin >> n >> q;
    for(int i=1 ; i<n ; i++){
        int u, v; cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1, 0);

    while(q--){
        int a, b; cin >> a >> b;
        int l = _lca(a, b);

        if(l == a or l == b){
            if(dep[a] < dep[b])
                swap(a, b);
            cnt[a] += 1;
            cnt[par[b][0]] -= 1;
        }else{
            cnt[a] += 1;
            cnt[b] += 1;
            cnt[l] -= 1;
            cnt[par[l][0]] -= 1;
        }
    }
    solve(1, 0);
    for(int i=1 ; i<=n ; i++)
        cout << cnt[i] << " ";
    cout << endl; 
}