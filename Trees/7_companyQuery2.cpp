// ~BhupinderJ
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vvi vector<vector<int>>

void dfs(int cv, int pv, vi* edge, vi &dep, vvi &par){
    dep[cv] = 1 + dep[pv];
    par[cv][0] = pv;
    for (int i = 1; i < 20; i++){
        par[cv][i] = par[par[cv][i-1]][i-1];
    }
    for(int v : edge[cv]){
        if(v == pv) continue;
        dfs(v, cv, edge, dep, par);
    }
}
int lca(int a, int b, vi &dep, vvi &par){
    if(dep[a] < dep[b]) 
        swap(a, b);
    int d = dep[a] - dep[b];
    for(int i=19 ; i>=0 ; i--){
        if((d>>i)&1) a = par[a][i];
    }
    if(a == b) return a;
    for(int i=19 ; i>=0 ; i--){
        if(par[a][i] != par[b][i]){
            a = par[a][i];
            b = par[b][i];
        }
    }
    return par[a][0];
}
signed main(){
    int n, q; cin >> n >> q;
    vi edge[n+1];
    for(int i=2 ; i<=n ; i++){
        int p; cin >> p;
        edge[p].push_back(i);
        edge[i].push_back(p);
    }    
    vi dep(n+1, 0);
    vvi par(n+1, vi(20, 0));

    dfs(1, 0, edge, dep, par);

    while(q--){
        int a, b; cin >> a >> b;
        cout << lca(a, b, dep, par) << endl;
    }
}