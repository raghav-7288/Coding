#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll mod = 1e9 + 7;

void dfs1(ll node, vector<ll> &vis, vector<ll> adj[], vector<ll> &order)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
            dfs1(it, vis, adj, order);
    }
    order.push_back(node);
}

void dfs2(ll node, vector<ll> &vis, vector<ll> adj[], vector<ll> &comp)
{
    vis[node] = 1;
    comp.push_back(node);
    for (auto it : adj[node])
    {
        if (!vis[it])
            dfs2(it, vis, adj, comp);
    }
}

void dfs3(ll comp, vector<ll> &vis, vector<ll> scc[], vector<ll> &comp_coins, vector<ll> &dp)
{
    vis[comp] = 1;
    dp[comp] = comp_coins[comp];
    for (auto it : scc[comp])
    {
        if (!vis[it])
            dfs3(it, vis, scc, comp_coins, dp);
        dp[comp] = max(dp[comp], comp_coins[comp] + dp[it]);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ll n, m;
    cin >> n >> m;
    vector<ll> adj[n + 1], adjr[n + 1];
    vector<ll> coins(n + 1), vis(n + 1), order, comp_coins(n + 1), comp_id(n + 1);

    for (ll i = 1; i <= n; i++)
        cin >> coins[i];

    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adjr[v].push_back(u);
    }

    for (ll i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs1(i, vis, adj, order);
    }

    reverse(order.begin(), order.end());

    fill(vis.begin(), vis.end(), 0);
    ll k = 0;

    for (auto i : order)
    {
        if (!vis[i])
        {
            vector<ll> comp;
            dfs2(i, vis, adjr, comp);

            for (auto node : comp)
            {
                comp_coins[k] += coins[node];
                comp_id[node] = k;
            }
            k++;
        }
    }

    vector<ll> scc[k];
    for (ll i = 1; i <= n; i++)
    {
        for (auto node : adj[i])
        {
            if (comp_id[i] != comp_id[node])
            {
                scc[comp_id[i]].push_back(comp_id[node]);
            }
        }
    }

    fill(vis.begin(), vis.end(), 0);
    vector<ll> dp(k);
    for (ll i = 0; i < k; i++)
    {
        if (!vis[i])
            dfs3(i, vis, scc, comp_coins, dp);
    }

    ll ans = 0;
    for (ll i = 0; i < k; i++)
    {
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}