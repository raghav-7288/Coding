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
    vector<ll> adj[n + 1];
    vector<vector<ll>> cap(n + 1, vector<ll>(n + 1));
    while (m--)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cap[u][v] += c;
    }
    cout << maxFlow(1, n, cap, adj);
    return 0;
}