// ~BhupinderJ
#include <bits/stdc++.h>
#define int long long
using namespace std;
#define vi vector<int>

void dfs(int cv, int pv, vi *edge, int dp[][2])
{
    dp[cv][1] = dp[cv][0] = 0;

    for (int v : edge[cv])
    {
        if (v == pv)
            continue;
        dfs(v, cv, edge, dp);
        dp[cv][0] += max(dp[v][0], dp[v][1]);
    }
    for (int v : edge[cv])
    {
        if (v == pv)
            continue;
        dp[cv][1] = max(dp[cv][1],
                        (1 + dp[v][0] + dp[cv][0] - max(dp[v][0], dp[v][1])));
    }
}
signed main()
{
    int n;
    cin >> n;
    vi edge[n + 1];

    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    int dp[n + 1][2];
    dfs(1, -1, edge, dp);

    cout << max(dp[1][0], dp[1][1]) << endl;
