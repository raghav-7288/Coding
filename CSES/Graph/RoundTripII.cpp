#include <bits/stdc++.h>
using namespace std;
bool dfs(int node, vector<int> &vis, vector<int> &pathVis, vector<int> &path, vector<int> &cycle, vector<int> adj[])
{
    vis[node] = 1;
    pathVis[node] = 1;
    path.push_back(node);
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (dfs(it, vis, pathVis, path, cycle, adj))
                return true;
        }
        else if (pathVis[it])
        {
            auto idx = find(path.begin(), path.end(), it);
            cycle.assign(idx, path.end());
            cycle.push_back(it);
            return true;
        }
    }
    pathVis[node] = 0;
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
    }
    vector<int> vis(n + 1), pathVis(n + 1), path, cycle;
    for (int i = 1; i <= n; i++)
    {

        if (!vis[i] && dfs(i, vis, pathVis, path, cycle, adj))
        {
            cout << cycle.size() << endl;
            for (auto c : cycle)
                cout << c << " ";
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}