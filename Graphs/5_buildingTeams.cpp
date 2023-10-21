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

bool dfs(int cv, vi &col, int cc){
    bool ans = true;
    col[cv] = cc;
    for(int v : edge[cv]){
        if(col[v] != -1){
            if(col[v] == cc) 
                return false;
            continue;
        }
        ans &= dfs(v, col, 1-cc);
    }
    return ans;
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
    vi col(n, -1);

    bool ans = true;
    for(int i=0 ; i<n ; i++) if(col[i] == -1){
        ans &= dfs(i, col, 1);
    }
    if(ans){
        cout << endl;
        for(int x : col)
            cout << (x ? x : 2) << " ";
        cout << endl;
    }else cout << "IMPOSSIBLE\n";
}
