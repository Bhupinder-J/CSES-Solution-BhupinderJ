// ~BhupinderJ
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vvi vector<vector<int>>
int n;

int bfs(int src, vi *edge, vi &dis)
{
    dis = vi(n + 1, 0);

    queue<int> pv;
    pv.push(src);

    vi vis(n + 1, 0);
    vis[src] = 1;

    int cv;

    while (pv.size())
    {
        cv = pv.front();
        pv.pop();

        for (int v : edge[cv])
            if (!vis[v])
            {
                pv.push(v);
                vis[v] = 1;
                dis[v] = 1 + dis[cv];
            }
    }
    return cv;
}
signed main()
{
    cin >> n;
    vi edge[n + 1];

    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    vi dis;
    int e1 = bfs(1, edge, dis);
    int e2 = bfs(e1, edge, dis);

    cout << dis[e2] << endl;
}
