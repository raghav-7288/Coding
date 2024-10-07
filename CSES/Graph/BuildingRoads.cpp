#include <bits/stdc++.h>
using namespace std;
class DSU
{
public:
    vector<int> p, s;
    DSU(int n)
    {
        s.resize(n, 1);
        p.resize(n);
        for (int i = 0; i < n; i++)
            p[i] = i;
    }
    int fp(int u)
    {
        if (p[u] == u)
            return u;
        else
            return p[u] = fp(p[u]);
    }
    bool ubs(int u, int v)
    {
        int pu = fp(u), pv = fp(v);
        if (pu == pv)
            return false;
        if (s[pu] <= s[pv])
        {
            p[pu] = pv;
            s[pv] += s[pu];
        }
        else
        {
            p[pv] = pu;
            s[pu] += s[pv];
        }
        return true;
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
    DSU ds(n + 1);
    for (int j = 0; j < m; j++)
    {
        int u, v;
        cin >> u >> v;
        ds.ubs(u, v);
    }
    vector<int> ulp;
    for (int i = 1; i <= n; i++)
    {
        if (i == ds.fp(i))
            ulp.push_back(i);
    }
    cout << ulp.size() - 1 << endl;
    for (int i = 1; i < ulp.size(); i++)
    {
        cout << ulp[0] << " " << ulp[i] << endl;
    }

    return 0;
}