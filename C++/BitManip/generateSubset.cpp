#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<vector<int>> allSubSets;
    vector<int> subSet;
    for (int i = 0; i < (1 << n); i++)
    {
        for (int b = 0; b < n; b++)
        {
            if (i & 1 << b)
            {
                subSet.push_back(a[b]);
            }
        }
        allSubSets.push_back(subSet);
        subSet.clear();
    }
    for (auto x : allSubSets)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}