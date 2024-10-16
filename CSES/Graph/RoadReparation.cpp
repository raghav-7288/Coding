#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
    vector<vector<ll>> edges;
    for (int i = 0; i < m; i++)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        edges.push_back({c, u, v});
    }
    sort(edges.begin(), edges.end());
    DSU ds(n + 1);
    ll ans = 0, ce = 0;
    for (auto e : edges)
    {
        if (ds.ubs(e[1], e[2]))
        {
            ce++;
            ans += e[0];
        }
    }
    if (ce != n - 1)
        cout << "IMPOSSIBLE";
    else
        cout << ans;
    return 0;
}