#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
private:
    vector<int> segmentTree;
    int n;
    void buildTree(const vector<int>& arr, int low, int high, int pos) {
        if (low == high) {segmentTree[pos] = arr[low];return;}
        int mid = (low + high) / 2;
        buildTree(arr, low, mid, 2 * pos + 1);
        buildTree(arr, mid + 1, high, 2 * pos + 2);
        segmentTree[pos] = segmentTree[2 * pos + 1] + segmentTree[2 * pos + 2];
    }
public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        int treeSize = 4 * n;
        segmentTree.resize(treeSize);
        buildTree(arr, 0, n - 1, 0);
    }
    void update(int index, int newValue) {
        updateElement(0, 0, n - 1, index, newValue);
    }
    int querySum(int left, int right) {
        return query(0, 0, n - 1, left, right);
    }
private:
    void updateElement(int pos, int low, int high, int index, int newValue) {
        if (low == high) {segmentTree[pos] = newValue;return;}
        int mid = (low + high) / 2;
        if (index <= mid) updateElement(2 * pos + 1, low, mid, index, newValue);
        else updateElement(2 * pos + 2, mid + 1, high, index, newValue);
        segmentTree[pos] = segmentTree[2 * pos + 1] + segmentTree[2 * pos + 2];
    }
    int query(int pos, int low, int high, int left, int right) {
        if (right < low || left > high) return 0;
        if (left <= low && right >= high) return segmentTree[pos];
        int mid = (low + high) / 2;
        int leftSum = query(2 * pos + 1, low, mid, left, right);
        int rightSum = query(2 * pos + 2, mid + 1, high, left, right);
        return leftSum + rightSum;
    }
};
// SegmentTree segmentTree(arr);
// segmentTree.update(index, newValue);
// segmentTree.querySum(left, right);
