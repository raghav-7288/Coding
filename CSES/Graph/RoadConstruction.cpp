#include <bits/stdc++.h>
using namespace std;
class DSU
{
public:
    vector<int> p, s;
    int ms = 1;
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
        return p[u] = fp(p[u]);
    }
    bool ubs(int u, int v)
    {
        int pu = fp(u), pv = fp(v);
        if (pu == pv)
            return false;
        if (s[pu] > s[pv])
            swap(pu, pv);
        p[pu] = pv;
        s[pv] += s[pu];
        if (s[pv] > ms)
            ms = s[pv];
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
    int nc = n;
    DSU ds(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (ds.ubs(u, v))
        {
            nc--;
        }
        cout << nc << " " << ds.ms << endl;
    }

    return 0;
}