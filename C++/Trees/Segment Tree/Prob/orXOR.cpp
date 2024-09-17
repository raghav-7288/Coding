/*
given a array first OR of adj the XOR of adj so on till single element(v)
query : update value and find out v
*/
#include <bits/stdc++.h>
using namespace std;
class SGT
{
public:
    vector<int> tree;
    int size;
    SGT(int n)
    {
        tree.resize(2 * n);
        size = log2(n);
    }
    void build(int index, int low, int high, int lvl, vector<int> &arr)
    {
        if (low == high)
        {
            tree[index] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * index + 1, low, mid, lvl + 1, arr);
        build(2 * index + 2, mid + 1, high, lvl + 1, arr);
        if (size % 2 == lvl % 2)
        {
            tree[index] = tree[2 * index + 1] ^ tree[2 * index + 2];
        }
        else
        {
            tree[index] = tree[2 * index + 1] | tree[2 * index + 2];
        }
    }
    int query(int index, int low, int high, int lvl, int pos, int val)
    {
        if (low == high)
        {
            tree[index] = val;
            return 0;
        }

        int mid = (low + high) / 2;

        if (pos <= mid)
        {
            query(2 * index + 1, low, mid, lvl + 1, pos, val);
        }
        else
        {
            query(2 * index + 2, mid + 1, high, lvl + 1, pos, val);
        }

        if (size % 2 == lvl % 2)
        {
            tree[index] = tree[2 * index + 1] ^ tree[2 * index + 2];
        }
        else
        {
            tree[index] = tree[2 * index + 1] | tree[2 * index + 2];
        }
        if (lvl == 0)
        {
            return tree[0];
        }
        return 0;
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
    // cout << log2(n);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> nq;
    vector<vector<int>> queries(nq);
    for (int i = 0; i < nq; i++)
    {
        int p, b;
        cin >> p >> b;
        queries[i] = {p, b};
    }
    SGT sgt(n);
    sgt.build(0, 0, n - 1, 0, a);
    for (auto q : queries)
    {
        cout << sgt.query(0, 0, n - 1, 0, q[0], q[1]) << endl;
    }
    return 0;
}
/*
8
5 1 7 2 0 3 8 4
4
1 1 -> 15
2 1 -> 15
5 2 -> 14
6 6 -> 6
*/

/*
4
1 3 7 4
3
0 2 -> 4
1 4 -> 1
2 8 -> 10
*/