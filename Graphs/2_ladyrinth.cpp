// ~BhupinderJ
#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define vi vector<int>
#define pii pair<int, int>
#define vvi vector<vector<int>>

const int nn = 1e3;
int n, m;
string path;
vector<string> g(nn);

int di[] = {-1, 0, 0, 1};
int dj[] = {0, -1, 1, 0};

bool isVal(int i, int j){
    return (i<n and j<m and i>=0 and j>=0);
}
bool bfs(int i, int j){
    map<pii, pii> from;
    queue<pii> pv;
    vvi vis(n, vi(m, 0));

    pv.push({i, j});
    from[{i, j}] = {i, j};
    vis[i][j] = 1;
    pii cv;
    bool found = false;

    while(pv.size()){
        cv = pv.front();
        if(g[cv.first][cv.second] == 'B'){  
            found = true;
            break;
        }
        pv.pop();

        for(int x=0 ; x<4 ; x++){
            int ii = cv.first + di[x];
            int jj = cv.second + dj[x];

            if(isVal(ii, jj) and (!vis[ii][jj]) and g[ii][jj] != '#'){
                from[{ii, jj}] = cv;
                pv.push({ii, jj});
                vis[ii][jj] = 1;
            }
        }
    }
    if(!found) return false;
    
    while(from[cv] != cv){
        pii nv = from[cv];
        char dir;
        if(nv.first == cv.first) dir = (nv.second > cv.second ? 'L' : 'R');
        else dir = (nv.first > cv.first ? 'U' : 'D');

        path.push_back(dir);
        cv = nv;
    }
    return true;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for(int i=0 ; i<n ; i++)
        cin >> g[i];
    bool ans = true;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++) if(g[i][j] == 'A'){
            ans = bfs(i, j);
        }
    }
    if(ans){
        cout << "YES\n";
        cout << path.size() << endl;
        reverse(path.begin(), path.end());
        cout << path << endl;
    }else cout << "NO\n";
    
}
