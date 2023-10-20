// ~BhupinderJ
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pii pair<int, int>
#define vvi vector<vector<int>>

class SegmentTree
{
private:
    vector<int> segmentTree;
    int n;
    void buildTree(const vector<int> &arr, int low, int high, int pos)
    {
        if (low == high)
        {
            segmentTree[pos] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        buildTree(arr, low, mid, 2 * pos + 1);
        buildTree(arr, mid + 1, high, 2 * pos + 2);
        segmentTree[pos] = segmentTree[2 * pos + 1] + segmentTree[2 * pos + 2];
    }

public:
    SegmentTree(const vector<int> &arr)
    {
        n = arr.size();
        int treeSize = 4 * n;
        segmentTree.resize(treeSize);
        buildTree(arr, 0, n - 1, 0);
    }
    void update(int index, int newValue)
    {
        updateElement(0, 0, n - 1, index, newValue);
    }
    int querySum(int left, int right)
    {
        return query(0, 0, n - 1, left, right);
    }

private:
    void updateElement(int pos, int low, int high, int index, int newValue)
    {
        if (low == high)
        {
            segmentTree[pos] = newValue;
            return;
        }
        int mid = (low + high) / 2;
        if (index <= mid)
            updateElement(2 * pos + 1, low, mid, index, newValue);
        else
            updateElement(2 * pos + 2, mid + 1, high, index, newValue);
        segmentTree[pos] = segmentTree[2 * pos + 1] + segmentTree[2 * pos + 2];
    }
    int query(int pos, int low, int high, int left, int right)
    {
        if (right < low || left > high)
            return 0;
        if (left <= low && right >= high)
            return segmentTree[pos];
        int mid = (low + high) / 2;
        int leftSum = query(2 * pos + 1, low, mid, left, right);
        int rightSum = query(2 * pos + 2, mid + 1, high, left, right);
        return leftSum + rightSum;
    }
};

const int nn = 2e5;
int ti = 0;
vi val(nn), eTour, cnt(nn, 0), pIdx(nn);
vi edge[nn];

void dfs(int cv, int pv)
{
    eTour.push_back(val[cv]);
    pIdx[cv] = ti++;
    for (int v : edge[cv])
    {
        if (v == pv)
            continue;
        dfs(v, cv);
        cnt[cv] += 1 + cnt[v];
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> val[i];
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        --x, --y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    dfs(0, -1);
    SegmentTree st(eTour);
    while (q--)
    {
        int tt, s, x;
        cin >> tt;
        if (tt == 1)
        {
            cin >> s >> x;
            s -= 1;
            st.update(pIdx[s], x);
        }
        else
        {
            cin >> s;
            s -= 1;
            cout << st.querySum(pIdx[s], pIdx[s] + cnt[s]) << endl;
        }
    }
}
