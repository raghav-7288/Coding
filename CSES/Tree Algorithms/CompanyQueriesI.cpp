#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll mod = 1e9 + 7;
void dfs(ll node, ll par, vector<ll> adj[], vector<vector<ll>> &parent)
{
    parent[node][0] = par;
    for (auto it : adj[node])
    {
        if (it == par)
            continue;
        dfs(it, node, adj, parent);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    ll n, q;
    cin >> n >> q;
    vector<ll> adj[n + 1];
    vector<vector<ll>> parent(n + 1, vector<ll>(20));
    for (ll i = 2; i <= n; i++)
    {
        int u;
        cin >> u;
        adj[u].push_back(i);
    }

    dfs(1, 0, adj, parent);

    for (int j = 1; j < 20; j++)
    {
        for (int i = 2; i <= n; i++)
        {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }

    while (q--)
    {
        ll x, k;
        cin >> x >> k;
        for (int i = 0; i <= 20; i++)
        {
            if (k & (1 << i))
            {
                x = parent[x][i];
            }
        }
        cout << (x == 0 ? -1 : x) << " ";
    }
    return 0;
}
