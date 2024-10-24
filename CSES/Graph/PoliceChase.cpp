#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll mod = 1e9 + 7;
int bfs(int n, int s, int sink, vector<int> adj[], vector<vector<int>> &cap, vector<int> &parent)
{
    fill(parent.begin(), parent.end(), -1);
    queue<pair<int, int>> q;
    q.push({s, INT_MAX});
    parent[s] = -2;
    while (!q.empty())
    {
        int node = q.front().first;
        int f = q.front().second;
        q.pop();
        for (auto it : adj[node])
        {
            if (parent[it] == -1 && cap[node][it])
            {
                parent[it] = node;
                int aug = min(f, cap[node][it]);
                if (it == sink)
                    return aug;
                q.push({it, aug});
            }
        }
    }
    return 0;
}
int maxFlow(int start, int n, vector<int> adj[], vector<vector<int>> &cap)
{
    int flow = 0, aug = 0;
    vector<int> parent(n + 1);
    while (aug = bfs(n, 1, n, adj, cap, parent))
    {
        flow += aug;
        int node = n;
        while (node != start)
        {
            int it = parent[node];
            cap[it][node] -= aug;
            cap[node][it] += aug;
            node = it;
        }
    }
    return flow;
}
void dfs(int node, vector<int> &vis, vector<int> adj[], vector<vector<int>> &cap)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it] && cap[node][it])
        {
            dfs(it, vis, adj, cap);
        }
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
    vector<int> adj[n + 1], vis(n + 1);
    vector<vector<int>> cap(n + 1, vector<int>(n + 1));
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cap[u][v]++;
        cap[v][u]++;
    }
    cout << maxFlow(1, n, adj, cap) << endl;
    dfs(1, vis, adj, cap);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
        {
            for (auto it : adj[i])
            {
                if (!vis[it])
                {
                    cout << i << " " << it << endl;
                }
            }
        }
    }
    return 0;
}