#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<long long>> adj(n + 1, vector<long long>(n + 1, -1));
    for (int i = 0; i <= n; i++)
        adj[i][i] = 0;
    for (int i = 0; i < m; i++)
    {
        long long u, v, w;
        cin >> u >> v >> w;
        if (adj[u][v] == -1)
        {
            adj[u][v] = w;
            adj[v][u] = w;
        }
        else
        {
            adj[u][v] = min(adj[u][v], w);
            adj[v][u] = min(adj[v][u], w);
        }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (adj[i][k] != -1 && adj[k][j] != -1)
                {
                    if (adj[i][j] == -1 || adj[i][k] + adj[k][j] < adj[i][j])
                    {
                        adj[i][j] = adj[i][k] + adj[k][j];
                    }
                }
            }
        }
    }
    for (int i = 0; i < q; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u > n || v > n || adj[u][v] == -1)
            cout << -1;
        else
            cout << adj[u][v];
        cout << endl;
    }
    return 0;
}