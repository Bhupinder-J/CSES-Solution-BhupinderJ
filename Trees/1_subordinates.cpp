// ~BhupinderJ
#include <bits/stdc++.h>
#define int long long
using namespace std;
 
const int mod = 1e9+7;
const int nmx = 1e6+1;
#define vi vector<int>
 
void dfs(int cv, int pv, vi *edge, vi &count){
    for(int v : edge[cv]){
        if(v == pv) continue;
        dfs(v, cv, edge, count);
        count[cv] += count[v] + 1;
    }
}
signed main(){
    int n; cin >> n;
    vector<int> edge[n+1];
 
    for(int i=2 ; i<=n ; i++){
        int p; cin >> p;
        edge[p].push_back(i);
        edge[i].push_back(p);
    }    
 
    vector<int> count(n+1, 0);
    dfs(1, -1, edge, count);
 
    for(int i=1 ; i<=n ; i++)  
        cout << count[i] <<" ";
    cout << endl;
}