#include <bits/stdc++.h>
using namespace std;
// void dfs(int node, int pl, int n, vector<int> &vis, vector<int> &path, vector<int> &curPath, vector<int> adj[])
// {
//     if (node == n)
//     {
//         if (pl > ans)
//         {
//             curPath = path;
//             ans = pl;
//         }
//         return;
//     }
//     vis[node] = 1;
//     path.push_back(node);
//     for (auto it : adj[node])
//     {
//         if (!vis[it])
//             dfs(it, pl + 1, n, vis, path, curPath, adj);
//     }
//     vis[node] = 0;
//     path.pop_back();
// }
void dfs(int node, vector<int> &vis, vector<int> adj[])
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
            dfs(it, vis, adj);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1], vis(n + 1), parent(n + 1), dis(n + 1, INT_MIN), inDeg(n + 1), ans;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        inDeg[v]++;
    }
    dfs(1, vis, adj);
    if (!vis[n])
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    dis[1] = 0;

    queue<int> q;

    for (int i = 1; i <= n; i++)
        if (!inDeg[i])
            q.push(i);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto it : adj[u])
        {
            if (dis[it] < dis[u] + 1)
            {
                dis[it] = dis[u] + 1;
                parent[it] = u;
            }
            if (!--inDeg[it])
                q.push(it);
        }
    }

    do
    {
        ans.push_back(n);
        n = parent[n];
    } while (n != 1);
    ans.push_back(1);

    cout << ans.size() << endl;
    reverse(ans.begin(), ans.end());
    for (auto node : ans)
        cout << node << " ";

    return 0;
}