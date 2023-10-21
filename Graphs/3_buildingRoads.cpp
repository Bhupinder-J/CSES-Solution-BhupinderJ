// ~BhupinderJ
#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define vi vector<int>
#define pii pair<int, int>
#define vvi vector<vector<int>>

const int nn = 1e5;
int n, m;
vi edge[nn];

void dfs(int cv, vi &vis){
    vis[cv] = 1;
    for(int v : edge[cv]){
        if(vis[v]) continue;
        dfs(v, vis);
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for(int i=0 ; i<m ; i++){
        int x, y; cin >> x >> y;
        --x, --y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    vi vis(n, 0);
    vi road;
    for(int i=0 ; i<n ; i++) if(!vis[i]){
        road.push_back(i+1);
        dfs(i, vis);
    }
    cout << road.size() - 1 << endl;
    for(int i=1 ; i<int(road.size()) ; i++){
        cout << road[i] <<" "<< road[i-1] << endl;
    }
}
