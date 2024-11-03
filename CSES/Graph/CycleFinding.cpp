#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, long long>> edges;
    vector<int> adj[n + 1], parent(n + 1, -1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        edges.push_back(make_tuple(u, v, w));
        adj[u].push_back(v);
    }
    vector<long long> dis(n + 1, 0);
    int x;
    for (int i = 0; i < n; i++)
    {
        x = -1;
        for (auto e : edges)
        {
            auto [u, v, ew] = e;
            if (dis[u] + ew < dis[v])
            {
                dis[v] = dis[u] + ew;
                parent[v] = u;
                x = v;
            }
        }
    }
    if (x == -1)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES\n";
        for (int i = 0; i < n; i++)
            x = parent[x];
        vector<int> cycle;
        int v = x;
        do
        {
            cycle.push_back(v);
            v = parent[v];
        } while (v != x);
        cycle.push_back(x);
        reverse(cycle.begin(), cycle.end());
        for (int node : cycle)
            cout << node << " ";
    }
    return 0;
}