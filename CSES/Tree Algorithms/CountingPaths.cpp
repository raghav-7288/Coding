#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll mod = 1e9 + 7;
// bool dfs(ll node, ll par, ll dest, vector<ll> &cntPaths, vector<ll> adj[])
// {
//     cntPaths[node]++;
//     if (node == dest)
//         return true;
//     for (auto it : adj[node])
//     {
//         if (it == par)
//             continue;
//         if (dfs(it, node, dest, cntPaths, adj))
//             return true;
//     }
//     cntPaths[node]--;
//     return false;
// }
void dfs(ll node, ll par, ll d, vector<vector<ll>> &parent, vector<ll> adj[], vector<ll> &depth)
{
    parent[node][0] = par;
    depth[node] = d;
    for (auto it : adj[node])
    {
        if (it == par)
            continue;
        dfs(it, node, d + 1, parent, adj, depth);
    }
}
void dfs_cnt(ll node, ll par, vector<ll> adj[], vector<ll> &cntPaths)
{
    for (auto it : adj[node])
    {
        if (it == par)
            continue;
        dfs_cnt(it, node, adj, cntPaths);
        cntPaths[node] += cntPaths[it];
    }
}
void findParent(ll n, vector<vector<ll>> &parent, vector<ll> adj[], vector<ll> &depth)
{
    dfs(1, 0, 0, parent, adj, depth);
    for (ll j = 1; j < 20; j++)
    {
        for (ll i = 2; i <= n; i++)
        {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }
}
ll LCA(ll u, ll v, vector<ll> &depth, vector<vector<ll>> &parent)
{
    if (depth[u] < depth[v])
        swap(u, v);
    ll diff = depth[u] - depth[v], i = 0;
    for (ll i = 0; i < 20; i++)
    {
        if (diff & (1 << i))
        {
            u = parent[u][i];
        }
    }
    if (u == v)
        return u;
    for (ll i = 19; i >= 0; i--)
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
    ll n, p;
    cin >> n >> p;
    vector<ll> adj[n + 1], cntPaths(n + 1), depth(n + 1);
    vector<vector<ll>> parent(n + 1, vector<ll>(20));
    for (ll i = 1; i < n; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // TLE
    // while (p--)
    // {
    //     ll u, v;
    //     cin >> u >> v;
    //     dfs(u, 0, v, cntPaths, adj);
    // }
    // for (ll i = 1; i <= n; i++)
    // {
    //     cout << cntPaths[i] << " ";
    // }
    findParent(n, parent, adj, depth);
    while (p--)
    {
        ll u, v;
        cin >> u >> v;
        cntPaths[u]++;
        cntPaths[v]++;
        ll lca = LCA(u, v, depth, parent);
        cntPaths[lca]--;
        cntPaths[parent[lca][0]]--;
    }
    dfs_cnt(1, 0, adj, cntPaths);
    for (ll i = 1; i <= n; i++)
    {
        cout << cntPaths[i] << " ";
    }
    return 0;
}