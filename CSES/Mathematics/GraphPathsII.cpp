#include <bits/stdc++.h>
using namespace std;
#define ll long long
void combine(vector<vector<ll>> &a, vector<vector<ll>> &b)
{
    ll n = a.size() - 1;
    vector<vector<ll>> c(n + 1, vector<ll>(n + 1, 2e18));
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            for (ll k = 1; k <= n; k++)
            {
                if (a[i][k] != 2e18 && b[k][j] != 2e18)
                {
                    c[i][j] = min(c[i][j], a[i][k] + b[k][j]);
                }
            }
        }
    }
    a = c;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> adj(n + 1, vector<ll>(n + 1, 2e18)), y(n + 1, vector<ll>(n + 1, 2e18));
    for (int i = 1; i <= n; i++)
        y[i][i] = 0;
    for (ll i = 0; i < m; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u][v] = min(w, adj[u][v]);
    }
    while (k)
    {
        if (k & 1)
            combine(y, adj);
        combine(adj, adj);
        k /= 2;
    }
    cout << (y[1][n] == 2e18 ? -1 : y[1][n]);
    return 0;
}