// ~BhupinderJ
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pii pair<int, int>
#define vvi vector<vector<int>>
int n;

void findInfo(int cv, int pv, vi *edge, vi &cnt, vi& dep, int& sum){
    cnt[cv] = 1;
    for(int v : edge[cv]){
        if(v == pv) continue;
        dep[v] = 1 + dep[cv];
        sum += dep[v];

        findInfo(v, cv, edge, cnt, dep, sum);
        cnt[cv] += cnt[v];
    }
}
void solve(int cv, int pv, vi*edge, vi& ans, vi& cnt){
    for(int v : edge[cv]){
        if(v == pv) continue;
        ans[v] = ans[cv] - 2*cnt[v] + n;
        solve(v, cv, edge, ans, cnt);
    }
}
signed main(){
    cin >> n;
    vi edge[n+1];
    for(int i=1 ; i<n ; i++){
        int x, y; cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    } 
    vi cnt(n+1, 0), dep(n+1, 0);
    int sum = 0;
    findInfo(1, -1, edge, cnt, dep, sum);

    vi ans(n+1);
    ans[1] = sum;
    solve(1, -1, edge, ans, cnt);

    for(int i=1 ; i<=n ; i++)
        cout << ans[i] <<" ";
    cout << endl;
}
