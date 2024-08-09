#include <bits/stdc++.h>
using namespace std;
vector<int> unionArrays(vector<int> a, vector<int> b)
{
    int p1 = 0, p2 = 0;
    vector<int> res;
    while (p1 < a.size() && p2 < b.size())
    {
        if (a[p1] == b[p2])
        {
            if (res.size() != 0)
            {
                if (res.back() != a[p1])
                {
                    res.push_back(a[p1]);
                }
            }
            else
            {
                res.push_back(a[p1]);
            }
            p1++;
            p2++;
        }
        else if (a[p1] < b[p2])
        {
            if (res.size() != 0)
            {
                if (res.back() != a[p1])
                {
                    res.push_back(a[p1]);
                }
            }
            else
            {
                res.push_back(a[p1]);
            }
            p1++;
        }
        else if (a[p1] > b[p2])
        {
            if (res.size() != 0)
            {
                if (res.back() != b[p2])
                {
                    res.push_back(b[p2]);
                }
            }
            else
            {
                res.push_back(b[p2]);
            }
            p2++;
        }
    }
    while (p1 != a.size())
    {
        if (res.back() != a[p1])
        {
            res.push_back(a[p1]);
        }
        p1++;
    }
    while (p2 != b.size())
    {
        if (res.back() != b[p2])
        {
            res.push_back(b[p2]);
        }
        p2++;
    }
    return res;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<int> a(n, 0);
    vector<int> b(m, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    vector<int> c = unionArrays(a, b);

    for (auto x : c)
    {
        cout << x << " ";
    }

    return 0;
}