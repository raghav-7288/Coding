#include <bits/stdc++.h>
using namespace std;
bool dfs(int node, int p, vector<int> &path, vector<int> &vis, vector<int> adj[], vector<int> &cycle)
{
    vis[node] = 1;
    path.push_back(node);
    for (auto it : adj[node])
    {
        if (it == p)
            continue;
        if (!vis[it])
        {
            if (dfs(it, node, path, vis, adj, cycle))
                return true;
        }
        else
        {
            auto idx = find(path.begin(), path.end(), it);
            if (idx != path.end())
            {
                cycle.assign(idx, path.end());
                cycle.push_back(it);
                return true;
            }
        }
    }
    path.pop_back();
    return false;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> path, vis(n + 1), cycle;
    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i])
        {
            if (dfs(i, -1, path, vis, adj, cycle))
            {
                cout << cycle.size() << endl;
                for (auto p : cycle)
                {
                    cout << p << " ";
                }
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
