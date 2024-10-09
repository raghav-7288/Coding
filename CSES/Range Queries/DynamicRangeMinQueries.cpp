#include <bits/stdc++.h>
using namespace std;
class SGT
{
public:
    vector<long long> tree, arr;
    SGT(int n, vector<long long> &_arr)
    {
        tree.resize(4 * n);
        arr = _arr;
    }
    void build(int i, int l, int h)
    {
        if (l == h)
        {
            tree[i] = arr[l];
            return;
        }
        int mid = (l + h) / 2;
        build(2 * i + 1, l, mid);
        build(2 * i + 2, mid + 1, h);
        tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
    }
    void update(int i, int l, int h, int pos, long long v)
    {
        if (l == h)
        {
            tree[i] = v;
            return;
        }
        int m = (l + h) / 2;
        if (pos <= m)
            update(2 * i + 1, l, m, pos, v);
        else
            update(2 * i + 2, m + 1, h, pos, v);
        tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
    }
    long long query(int i, int l, int h, int left, int right)
    {
        if (right < l || h < left)
            return INT_MAX;
        if (left <= l && h <= right)
            return tree[i];
        int m = (l + h) / 2;
        return min(query(2 * i + 1, l, m, left, right), query(2 * i + 2, m + 1, h, left, right));
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
    SGT st(n, arr);
    st.build(0, 0, n - 1);
    for (int i = 0; i < q; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int p;
            long long v;
            cin >> p >> v;
            st.update(0, 0, n - 1, p - 1, v);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << st.query(0, 0, n - 1, l - 1, r - 1) << endl;
        }
    }
    return 0;
}