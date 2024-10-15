#include <bits/stdc++.h>
using namespace std;

class SGT
{
public:
    vector<int> tree, arr;
    SGT(int n, vector<int> &_arr)
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
        int m = (l + h) / 2;
        build(i * 2 + 1, l, m);
        build(i * 2 + 2, m + 1, h);
        tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
    }

    int query(int i, int l, int h, int r)
    {
        if (tree[i] < r)
            return -1; // Return -1 if no value satisfies the condition

        if (l == h)
        {
            tree[i] -= r; // Update the value of the segment tree node
            return l;     // Return the index
        }

        int m = (l + h) / 2;
        int res;
        if (tree[2 * i + 1] >= r)
            res = query(2 * i + 1, l, m, r);
        else
            res = query(2 * i + 2, m + 1, h, r);

        tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]); // Update the current node

        return res;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<int> h(n);
    for (auto &r : h)
        cin >> r;
    SGT sg(n, h);
    sg.build(0, 0, n - 1);
    while (m--)
    {
        int r;
        cin >> r;
        int res = sg.query(0, 0, n - 1, r);
        if (res == -1)
            cout << 0 << " ";
        else
            cout << res + 1 << " "; // Add 1 to match 1-based indexing
    }
    return 0;
}
