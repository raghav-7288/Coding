#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll mod = 1e9 + 7;
void dfs(ll node, ll par, int d, vector<ll> &depth, vector<ll> adj[], vector<vector<ll>> &parent)
{
    parent[node][0] = par;
    depth[node] = d;
    for (auto it : adj[node])
    {
        if (it == par)
            continue;
        dfs(it, node, d + 1, depth, adj, parent);
    }
}
int getLCA(int u, int v, vector<ll> &depth, vector<vector<ll>> &parent)
{
    if (depth[u] < depth[v])
        swap(u, v);
    ll diff = depth[u] - depth[v];
    for (int i = 0; i < 20; i++)
    {
        if (diff & (1 << i))
        {
            u = parent[u][i];
        }
    }
    if (u == v)
        return u;
    for (int i = 19; i >= 0; i--)
    {
        if (parent[u][i] && parent[u][i] != parent[v][i])
        {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, q;
    cin >> n >> q;
    vector<ll> adj[n + 1], depth(n + 1);
    vector<vector<ll>> parent(n + 1, vector<ll>(20));
    for (ll i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0, 0, depth, adj, parent);
    for (int j = 1; j < 20; j++)
    {
        for (int i = 2; i <= n; i++)
        {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }
    while (q--)
    {
        ll u, v;
        cin >> u >> v;
        cout << depth[u] + depth[v] - 2 * depth[getLCA(u, v, depth, parent)] << " ";
    }
    return 0;
}
