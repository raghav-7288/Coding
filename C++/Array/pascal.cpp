#include <bits/stdc++.h>
using namespace std;
// vector<int> genRow(int n)
// {
    // vector<int> res;
    // res.push_back(1);
    // int ans = 1;
    // for (int i = 1; i < n; i++)
    // {
    //     res.push_back(ans = (ans * (n - i) / i));
    // }
    // return res;
// }
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<vector<int>> pt;
    vector<int> row;
    pt.push_back({1});
    pt.push_back({1, 1});
    for (int i = 2; i < n; i++)
    {
        row.push_back(1);
        for (int j = 1; j < i; j++)
        {
            row.push_back(pt[i - 1][j] + pt[i - 1][j - 1]);
        }
        row.push_back(1);
        pt.push_back(row);
        row.clear();
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     pt.push_back(genRow(i));
    // }
    for (auto x : pt)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}
