// ~BhupinderJ
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vvi vector<vector<int>>
const int N = 2e5;

vi edge[N+1];
vi dep(N+1, 0);
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
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q; cin >> n >> q;    
    for(int i=1 ; i<n ; i++){
        int a, b; cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    dfs(1, 0);
    while(q--){
        int a, b; cin >> a >> b;
        cout << dep[a] + dep[b] - 2*dep[_lca(a, b)] << endl;
    }
}
