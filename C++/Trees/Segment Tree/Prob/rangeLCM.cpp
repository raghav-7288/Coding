#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if (!a)
        return b;
    return gcd(b % a, a);
}
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
        tree[index] = tree[2 * index + 1] * tree[2 * index + 2] / gcd(tree[2 * index + 1], tree[2 * index + 2]);
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
        tree[index] = tree[2 * index + 1] * tree[2 * index + 2] / gcd(tree[2 * index + 1], tree[2 * index + 2]);
    }
    int query(int index, int low, int high, int left, int right)
    {
        if (high < left || right < low)
        {
            return 1;
        }
        if (left <= low && high <= right)
        {
            return tree[index];
        }
        int mid = (low + high) / 2;
        int l = query(2 * index + 1, low, mid, left, right);
        int r = query(2 * index + 2, mid + 1, high, left, right);

        return (l * r) / gcd(l, r);
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
    for (int i = 0; i < nq; i++)
    {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 2)
        {
            sgt.update(0, 0, n - 1, l, r);
        }
        else
            cout << sgt.query(0, 0, n - 1, l, r) << endl;
    }
    return 0;
}