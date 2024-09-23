/*
query : give bitwise and of elements form l-r
*/
#include <bits/stdc++.h>
using namespace std;
class SGT
{
public:
    vector<int> tree;
    SGT(int n)
    {
        tree.resize(4 * n);
    }
    void build(int index, int low, int high, vector<int> &arr)
    {
        if (low == high)
        {
            tree[index] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * index + 1, low, mid, arr);
        build(2 * index + 2, mid + 1, high, arr);
        tree[index] = max(tree[2 * index + 1], tree[2 * index + 2]);
    }
    void update(int index, int low, int high, int pos, int val)
    {
        if (low == high)
        {
            tree[index] = val;
            return;
        }
        int mid = (low + high) / 2;
        if (pos <= mid)
        {
            update(2 * index + 1, low, mid, pos, val);
        }
        else
        {
            update(2 * index + 2, mid + 1, high, pos, val);
        }
        tree[index] = max(tree[2 * index + 1], tree[2 * index + 2]);
    }
    int query(int index, int low, int high, int left, int right)
    {
        if (right < low || high < left)
        {
            return INT_MIN;
        }
        else if (left <= low && high <= right)
        {
            return tree[index];
        }
        int mid = (low + high) / 2;
        return max(query(2 * index + 1, low, mid, left, right), query(2 * index + 2, mid + 1, high, left, right));
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, nq;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    SGT sgt(n);
    sgt.build(0, 0, n - 1, arr);
    cin >> nq;
    vector<vector<int>> queries;
    for (int i = 0; i < nq; i++)
    {
        int t, l, r;
        cin >> t >> l >> r;
        queries.push_back({t, l, r});
    }
    for (auto q : queries)
    {
        if (q[0] == 1)
        {
            sgt.update(0, 0, n - 1, q[1], q[2]);
        }
        else
            cout << sgt.query(0, 0, n - 1, q[1], q[2]) << endl;
    }
    return 0;
}

/*
10
1 2 3 4 5 6 7 8 9 10
5
2 3 6
1 3 7
2 3 6
1 5 9
2 5 8

4
4
0
*/