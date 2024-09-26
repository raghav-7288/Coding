/*
We have an array arr[0 . . . n-1]. We should be able to,
Find the sum of elements from index l to r where 0 <= l <= r <= n-1
Change the value of a specified element of the array to a new value x.
We need to do arr[i] = x where 0 <= i <= n-1.

n->size of array-> power of 2;
2*n->size of trre
*/
#include <bits/stdc++.h>
using namespace std;
class SGT
{
public:
    vector<int> tree;
    int n;
    SGT(int _n)
    {
        tree.resize(2 * _n);
        n = _n;
    }
    void build(vector<int> &arr)
    {
        for (int i = 0; i < n; i++)
        {
            tree[n + i] = arr[i];
        }
        for (int i = n - 1; i > 0; i--)
        {
            tree[i] = tree[2 * i] + tree[2 * i + 1];
        }
    }
    void update(int pos, int val)
    {
        tree[n + pos] = val;
        pos += n;
        for (int i = pos; i > 1; i /= 2)
        {
            tree[i / 2] = tree[i] + tree[i ^ 1];
        }
    }
    int query(int l, int r)
    {
        int ans = 0;
        for (l += n, r += n; l < r; l /= 2, r /= 2)
        {
            if (l & 1)
                ans += tree[l++];
            if (r & 1)
                ans += tree[--r];
        }
        return ans;
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
    sgt.build(arr);
    cin >> nq;
    for (int i = 0; i < nq; i++)
    {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1)
        {
            sgt.update(l, r);
        }
        else
        {
            cout << sgt.query(l, r + 1) << endl;
        }
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

22
25
33
*/