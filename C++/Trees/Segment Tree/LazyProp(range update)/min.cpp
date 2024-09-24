/*
give min of l-r
uodate l-r by +val
*/
#include <bits/stdc++.h>
using namespace std;

class SGT
{
public:
    vector<int> tree, lazy, arr;
    SGT(int n, vector<int> &_arr)
    {
        tree.resize(4 * n);
        lazy.resize(4 * n);
        arr = _arr;
    }
    void build(int index, int low, int high)
    {
        if (low == high)
        {
            tree[index] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * index + 1, low, mid);
        build(2 * index + 2, mid + 1, high);

        tree[index] = min(tree[2 * index + 1], tree[2 * index + 2]);
    }
    void update(int index, int low, int high, int left, int right, int val)
    {
        if (lazy[index])
        {
            tree[index] += lazy[index];
            if (low != high)
            {
                lazy[2 * index + 1] += lazy[index];
                lazy[2 * index + 2] += lazy[index];
            }
            lazy[index] = 0;
        }
        if (right < low || high < left)
        {
            return;
        }
        else if (left <= low && high <= right)
        {
            tree[index] += val;
            if (low != high)
            {
                lazy[2 * index + 1] += val;
                lazy[2 * index + 2] += val;
            }
            return;
        }
        int mid = (low + high) / 2;
        update(2 * index + 1, low, mid, left, right, val);
        update(2 * index + 2, mid + 1, high, left, right, val);

        tree[index] = min(tree[2 * index + 1], tree[2 * index + 2]);
    }
    int query(int index, int low, int high, int left, int right)
    {
        if (lazy[index])
        {
            tree[index] += lazy[index];
            if (low != high)
            {
                lazy[2 * index + 1] += lazy[index];
                lazy[2 * index + 2] += lazy[index];
            }
            lazy[index] = 0;
        }
        if (right < low || high < left)
        {
            return INT_MAX;
        }
        else if (left <= low && high <= right)
        {
            return tree[index];
        }
        int mid = (low + high) / 2;
        return min(query(2 * index + 1, low, mid, left, right), query(2 * index + 2, mid + 1, high, left, right));
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
    SGT sgt(n, arr);
    sgt.build(0, 0, n - 1);
    cin >> nq;
    vector<vector<int>> queries;
    for (int i = 0; i < nq; i++)
    {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1)
        {
            int val;
            cin >> val;
            queries.push_back({t, l, r, val});
        }
        else
        {
            queries.push_back({t, l, r});
        }
    }
    for (auto q : queries)
    {
        if (q[0] == 1)
        {
            sgt.update(0, 0, n - 1, q[1], q[2], q[3]);
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
1 3 7 2
2 3 6
1 5 9 5
2 5 8

4
6
13
*/