#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll mod = 1e9 + 7;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<ll> dis(n + 1, LONG_LONG_MIN), vis(n + 1), adj[n + 1];
    vector<tuple<int, int, int>> edges;
    queue<int> q;
    while (m--)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        edges.push_back(make_tuple(u, v, w));
        adj[u].push_back(v);
    }
    dis[1] = 0;
    for (int i = 1; i < n; i++)
    {
        for (auto e : edges)
        {
            auto [f, t, w] = e;
            if (dis[f] != LONG_LONG_MIN && dis[f] + w > dis[t])
            {
                dis[t] = dis[f] + w;
            }
        }
    }
    for (auto e : edges)
    {
        auto [f, t, w] = e;
        if (dis[f] != LONG_LONG_MIN && dis[f] + w > dis[t])
        {
            if (t == n)
            {
                cout << -1;
                return 0;
            }
            q.push(t);
            vis[t] = 1;
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        if (node == n)
        {
            cout << -1;
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