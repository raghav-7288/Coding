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
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    DSU ds(n * m);
    int cx[4] = {-1, 0, 1, 0}, cy[4] = {0, 1, 0, -1};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.')
            {
                for (int k = 0; k < 4; k++)
                {
                    int nr = i + cx[k], nc = j + cy[k];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '.')
                    {
                        ds.ubs(i * m + j, nr * m + nc);
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && ds.fp(i * m + j) == i * m + j)
                ans++;
        }
    }
    cout << ans;
    return 0;
}