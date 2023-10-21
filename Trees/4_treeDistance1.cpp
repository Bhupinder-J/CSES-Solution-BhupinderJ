// ~BhupinderJ
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vvi vector<vector<int>>
int n; 

int bfs(int src, vi *edge){
    int cv;
    queue<int> pv;
    vi vis(n+1, 0);
    pv.push(src);
    vis[src] = 1;

    while(pv.size()){
        cv = pv.front();
        pv.pop();
        for(int v : edge[cv]){
            if(vis[v]) continue;
            pv.push(v);
            vis[v] = 1;
        }
    }
    return cv;
}
void solve(int cv, int pv, vi* edge, vi& dis, vi& dep){
    for(int v : edge[cv]){
        if(v == pv) continue;
        dep[v] =  1 + dep[cv];

        dis[v] = max(dis[v], dep[v]);
        solve(v, cv, edge, dis, dep);
    }
}
signed main(){
    cin >> n;
    vi edge[n+1];
    for(int i=1; i<n ; i++){
        int x, y; cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }    
    int e1 = bfs(1, edge);
    int e2 = bfs(e1, edge);
    
    vi dis(n+1, 0), dep(n+1, 0);
    solve(e1, -1, edge, dis, dep);

    dep = vi(n+1, 0);
    solve(e2, -1, edge, dis, dep);


    for(int i=1 ; i<=n ; i++)
        cout << dis[i] <<" ";
    cout << endl;
}
