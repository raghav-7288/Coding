#include <bits/stdc++.h>
using namespace std;
bool dfs(int node, int t, vector<int> &team, vector<int> adj[])
{
    team[node] = t;
    for (auto it : adj[node])
    {
        if (team[it] == -1)
        {
            if (!dfs(it, !t, team, adj))
                return false;
        }
        else
        {
            if (team[it] == t)
                return false;
        }
    }
    return true;
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
    for (int j = 0; j < m; j++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> team(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        if (team[i] == -1)
        {
            if (!dfs(i, 0, team, adj))
            {
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << team[i] + 1 << " ";
    }
    return 0;
}
