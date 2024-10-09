#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, long long>> edges;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(make_tuple(u, v, w));
        adj[u].push_back(v);
    }
    vector<long long> dis(n + 1, LONG_LONG_MIN);
    dis[1] = 0;
    for (int i = 1; i < n; i++)
    {
        for (auto e : edges)
        {
            auto [u, v, ew] = e;
            if (dis[u] != LONG_LONG_MIN && dis[u] + ew > dis[v])
            {
                dis[v] = dis[u] + ew;
            }
        }
    }
    queue<int> q;
    vector<int> vis(n + 1);
    for (auto e : edges)
    {
        auto [u, v, ew] = e;
        if (dis[u] != LONG_LONG_MIN && dis[u] + ew > dis[v])
        {
            if (v == n)
            {
                cout << "-1";
                return 0;
            }
            q.push(v);
            vis[v] = 1;
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        if (node == n)
        {
            cout << "-1";
            return 0;
        }
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                q.push(it);
                vis[it] = 1;
            }
        }
    }
    cout << dis[n];
    return 0;
}