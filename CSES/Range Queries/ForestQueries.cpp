#include <bits/stdc++.h>
using namespace std;

class SGT
{
public:
    vector<int> tree;
    vector<vector<char>> forest;
    int n;
    SGT(int _n, vector<vector<char>> &_arr)
    {
        tree.resize(4 * _n);
        forest = _arr;
        n = forest.size();
    }
    void build(int i, int l, int h)
    {
        if (l == h)
        {
            tree[i] = (forest[l / n][l % n] == '*' ? 1 : 0);
            return;
        }
        int m = (l + h) / 2;
        build(2 * i + 1, l, m);
        build(2 * i + 2, m + 1, h);
        tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
    }
    int query(int i, int l, int h, int left, int right)
    {
        if (right < l || h < left)
            return 0;
        if (left <= l && h <= right)
            return tree[i];
        int m = (l + h) / 2;
        return query(2 * i + 1, l, m, left, right) + query(2 * i + 2, m + 1, h, left, right);
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
    vector<vector<char>> forest(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> forest[i][j];
        }
    }
    // SGT sg(n * n, forest);
    // sg.build(0, 0, n * n - 1);
    // while (q--)
    // {
    //     int r1, c1, r2, c2;
    //     cin >> r1 >> c1 >> r2 >> c2;
    //     r1--;
    //     c1--;
    //     r2--;
    //     c2--;
    //     int total_trees = 0;
    //     for (int row = r1; row <= r2; row++)
    //     {
    //         total_trees += sg.query(0, 0, n * n - 1, row * n + c1, row * n + c2);
    //     }
    //     cout << total_trees << endl;
    // }
    vector<vector<int>> pre(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            pre[i][j] = ((forest[i - 1][j - 1] == '*') ? 1 : 0) + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
        }
    }
    while (q--)
    {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        cout << pre[r2][c2] - pre[r1 - 1][c2] - pre[r2][c1 - 1] + pre[r1 - 1][c1 - 1] << endl;
    }
    return 0;
}
