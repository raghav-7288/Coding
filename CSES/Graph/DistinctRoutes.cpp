#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll mod = 1e9 + 7;
ll bfs(ll source, ll sink, vector<ll> &parent, vector<ll> adj[], vector<vector<ll>> &cap)
{
    fill(parent.begin(), parent.end(), -1);
    parent[source] = -2;
    queue<pair<ll, ll>> q;
    q.push({source, 1e18});
    while (!q.empty())
    {
        ll node = q.front().first, flow = q.front().second;
        q.pop();
        for (auto it : adj[node])
        {
            if (parent[it] == -1 && cap[node][it] > 0)
            {
                parent[it] = node;
                ll aug = min(flow, cap[node][it]);
                if (it == sink)
                    return aug;
                q.push({it, aug});
            }
        }
    }
    return 0;
}
ll maxFlow(ll source, ll sink, vector<vector<ll>> &cap, vector<ll> adj[])
{
    ll flow = 0, aug;
    vector<ll> parent(sink + 1, -1);
    while (aug = bfs(source, sink, parent, adj, cap))
    {
        flow += aug;
        ll cur = sink;
        while (cur != source)
        {
            ll par = parent[cur];
            cap[par][cur] -= aug;
            cap[cur][par] += aug;
            cur = par;
        }
    }
    return flow;
}
void dfs(int node, int n, vector<ll> &vis, vector<pair<ll, ll>> _adj[], vector<vector<ll>> &cap, vector<ll> &path)
{
    path.push_back(node);
    if (node == n)
        return;
    for (auto it : _adj[node])
    {
        if (!cap[node][it.first] && !vis[it.second])
        {
            vis[it.second] = 1;
            dfs(it.first, n, vis, _adj, cap, path);
            return;
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<ll> adj[n + 1], path, vis(m);
    vector<pair<ll, ll>> _adj[n + 1];
    vector<vector<ll>> cap(n + 1, vector<ll>(n + 1));
    for (int i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        _adj[u].push_back({v, i});
        cap[u][v]++;
    }
    ll mf = maxFlow(1, n, cap, adj);
    cout << mf;
    while (mf--)
    {
        path.clear();
        dfs(1, n, vis, _adj, cap, path);
        cout << endl
             << path.size() << endl;
        for (auto p : path)
            cout << p << " ";
    }
    return 0;
}