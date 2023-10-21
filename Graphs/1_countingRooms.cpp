// ~BhupinderJ
#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define vi vector<int>
#define pii pair<int, int>
#define vvi vector<vector<int>>

const int nn = 1e3;
int n, m;
vector<string> g(nn);
vvi vis(nn, vi(nn, 0));

int di[] = {-1, 0, 0, 1};
int dj[] = {0, -1, 1, 0};

bool isVal(int i, int j){
    return (i<n and j<m and i>=0 and j>=0);
}
void dfs(int i, int j){
    vis[i][j] = 1;
    for(int k=0 ; k<4 ; k++){
        int ii = i + di[k];
        int jj = j + dj[k];

        if(isVal(ii, jj) and g[ii][jj] == '.' and (!vis[ii][jj]))
            dfs(ii, jj);
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0 ; i<n ; i++)
        cin >> g[i];

    int cnt = 0;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++) if(!vis[i][j] and g[i][j] == '.'){
            cnt += 1;
            dfs(i, j);
        }
    }
    cout << cnt << endl;
}
