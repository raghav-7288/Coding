#include <bits/stdc++.h>
using namespace std;
class SGT
{
public:
    vector<long long> tree, lp, arr;
    SGT(int n, vector<long long> &_arr)
    {
        tree.resize(4 * n);
        lp.resize(4 * n, 0);
        arr = _arr;
    }
    void build(int i, int l, int h)
    {
        if (l == h)
        {
            tree[i] = arr[l];
            return;
        }
        int m = (l + h) / 2;
        build(2 * i + 1, l, m);
        build(2 * i + 2, m + 1, h);
        tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
    }
    void update(int i, int l, int h, int left, int right, long long v)
    {
        if (lp[i])
        {
            tree[i] += lp[i] * (h - l + 1);
            if (l != h)
            {
                lp[2 * i + 1] += lp[i];
                lp[2 * i + 2] += lp[i];
            }
            lp[i] = 0;
        }
        if (h < left || right < l)
            return;
        if (left <= l && h <= right)
        {
            tree[i] += v * (h - l + 1);
            if (l != h)
            {
                lp[2 * i + 1] += v;
                lp[2 * i + 2] += v;
            }
            return;
        }
        int m = (l + h) / 2;
        update(2 * i + 1, l, m, left, right, v);
        update(2 * i + 2, m + 1, h, left, right, v);
        tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
    }
    long long getVal(int i, int l, int h, int p)
    {
        if (lp[i])
        {
            tree[i] += lp[i] * (h - l + 1);
            if (l != h)
            {
                lp[2 * i + 1] += lp[i];
                lp[2 * i + 2] += lp[i];
            }
            lp[i] = 0;
        }
        if (l == h)
            return tree[i];
        int m = (l + h) / 2;
        if (p <= m)
            return getVal(2 * i + 1, l, m, p);
        return getVal(2 * i + 2, m + 1, h, p);
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, q;
    cin >> n >> q;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    SGT sg(n, arr);
    sg.build(0, 0, n - 1);
    for (int i = 0; i < q; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int l, r;
            long long v;
            cin >> l >> r >> v;
            sg.update(0, 0, n - 1, l - 1, r - 1, v);
        }
        else
        {
            int p;
            cin >> p;
            cout << sg.getVal(0, 0, n - 1, p - 1) << endl;
        }
    }
    return 0;
}