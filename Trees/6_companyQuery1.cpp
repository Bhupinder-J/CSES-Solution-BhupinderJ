// ~BhupinderJ
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vvi vector<vector<int>>

void dfs(int cv, int pv, vi* edge, vvi &par){
    par[cv][0] = pv;
    for(int i=1 ; i<20 ; i++){
        par[cv][i] = par[par[cv][i-1]][i-1];
    }
    for(int v : edge[cv]){
        if(v == pv) 
            continue;
        dfs(v, cv, edge, par);
    }
}
signed main(){
    int n, q; cin >> n >> q;

    vi edge[n+1];
    for(int i=2 ; i<=n ; i++){
        int p; cin >> p;
        edge[i].push_back(p);
        edge[p].push_back(i);
    }    
    vvi par(n+1, vi(20, 0));
    dfs(1, 0, edge, par);

    while(q--){
        int x, k; cin >> x >> k;
        for(int i=19 ; i>=0 ; i--){
            if((k>>i)&1) x = par[x][i];
        }
        cout << (x ? x : -1) << endl;
    }
}
