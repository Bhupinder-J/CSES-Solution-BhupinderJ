// ~BhupinderJ
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vvi vector<vector<int>>
int n;

/* ASSUMING CV IS A PART OF LONGEST PATH*/

void dfs(int cv, int pv, vi *edge, int &dia, vi &dep)
{
    vi mxDep;

    for (int v : edge[cv])
    {
        if (v == pv)
            continue;
        dfs(v, cv, edge, dia, dep);
        dep[cv] = max(dep[cv], 1 + dep[v]);
        mxDep.push_back(1 + dep[v]);
    }

    sort(mxDep.rbegin(), mxDep.rend());
    int curAns = 0;
    for (int i = 0; i < min(int(mxDep.size()), 2); i++)
        curAns += mxDep[i];

    dia = max(dia, curAns);
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

    int dia = 0;
    vi dep(n + 1, 0);
    dfs(1, -1, edge, dia, dep);

    cout << dia << endl;
}

/* DP ON TREES */

// void dfs(int cv, int pv, vi *edge, vi &maxDeapth)
// {
//     for (int v : edge[cv])
//         if (v != pv)
//         {
//             dfs(v, cv, edge, maxDeapth);
//             maxDeapth[cv] = max(1 + maxDeapth[v], maxDeapth[cv]);
//         }
// }
// void findDiameter(int cv, int pv, vi *edge, vi &maxDeapth, int &diameter)
// {
//     vi deapth(0);

//     for (int v : edge[cv])
//         if (v != pv)
//         {
//             findDiameter(v, cv, edge, maxDeapth, diameter);
//             deapth.push_back(maxDeapth[v]);
//         }

//     sort(deapth.rbegin(), deapth.rend());

//     int curAns = 0;
//     if (deapth.empty())
//         curAns = 0;
//     else if (deapth.size() == 1)
//         curAns = 1 + deapth[0];
//     else
//         curAns = 2 + deapth[0] + deapth[1];

//     diameter = max(diameter, curAns);
// }
// signed main()
// {
//     cin >> n;
//     vi edge[n + 1];

//     for (int i = 1; i < n; i++)
//     {
//         int x, y;
//         cin >> x >> y;
//         edge[x].push_back(y);
//         edge[y].push_back(x);
//     }

//     vi maxDeapth(n + 1, 0);
//     dfs(1, -1, edge, maxDeapth);

//     int diameter = 0;
//     findDiameter(1, -1, edge, maxDeapth, diameter);

//     cout << diameter << endl;
// }

/* USING 2 BFS'S */

// int bfs(int src, vi *edge, vi &dis)
// {
//     dis = vi(n + 1, 0);

//     queue<int> pv;
//     pv.push(src);

//     vi vis(n + 1, 0);
//     vis[src] = 1;

//     int cv;

//     while (pv.size())
//     {
//         cv = pv.front();
//         pv.pop();

//         for (int v : edge[cv])
//             if (!vis[v])
//             {
//                 pv.push(v);
//                 vis[v] = 1;
//                 dis[v] = 1 + dis[cv];
//             }
//     }
//     return cv;
// }
// signed main()
// {
//     cin >> n;
//     vi edge[n + 1];

//     for (int i = 1; i < n; i++)
//     {
//         int x, y;
//         cin >> x >> y;
//         edge[x].push_back(y);
//         edge[y].push_back(x);
//     }

//     vi dis;
//     int e1 = bfs(1, edge, dis);
//     int e2 = bfs(e1, edge, dis);

//     cout << dis[e2] << endl;
// }
