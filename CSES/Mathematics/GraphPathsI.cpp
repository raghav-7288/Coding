#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9 + 7;
void matMul(vector<vector<ll>> &a, vector<vector<ll>> &b)
{
    int n = a.size() - 1;
    vector<vector<ll>> c(n + 1, vector<ll>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                c[i][j] += (a[i][k] * b[k][j]) % mod;
            }
            c[i][j] %= mod;
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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> adj(n + 1, vector<ll>(n + 1)), y(n + 1, vector<ll>(n + 1));
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] += 1;
    }
    for (int i = 1; i <= n; i++)
        y[i][i] = 1;
    while (k)
    {
        if (k & 1)
            matMul(y, adj);
        matMul(adj, adj);
        k /= 2;
    }
    cout << y[1][n];
    return 0;
}