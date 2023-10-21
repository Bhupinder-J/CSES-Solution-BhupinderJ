// ~BhupinderJ
#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define vi vector<int>
#define pii pair<int, int>
#define vvi vector<vector<int>>

const int nn = 1e5;
int n, m;
vi edge[nn], path;

bool bfs(int src, int des){
    vi vis(n, 0);
    queue<int> pv;
    map<int, int> par;

    vis[src] = 1;
    pv.push(src);
    par[src] = src;
    bool ans = false;

    while(pv.size()){
        int cv = pv.front();
        if(cv == des){
            ans = true;
            break;
        } 
        pv.pop();
        for(int v : edge[cv]){
            if(vis[v]) continue;
            vis[v] = 1;
            pv.push(v);
            par[v] = cv;
        }
    }
    if(!ans) return ans;
    while(par[des] != des){
        path.push_back(des);
        des = par[des];
    }
    path.push_back(0);
    reverse(path.begin(), path.end());
    return true;
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
    bool ans = bfs(0, n-1);
    if(ans){
        cout << path.size() << endl;
        for(int x : path)
            cout << x+1 <<" ";
        cout << endl;
    }else cout << "IMPOSSIBLE\n";
}
