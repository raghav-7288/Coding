#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll mod = 1e9 + 7;
bool dfs(int node, int par, vector<int> &vis, vector<int> &cycle, vector<int> &path, vector<int> adj[])
{
    vis[node] = 1;
    path.push_back(node);
    for (auto it : adj[node])
    {
        if (it == par)
            continue;
        if (!vis[it])
        {
            if (dfs(it, node, vis, cycle, path, adj))
                return true;
        }
        else
        {
            auto idx = find(path.begin(), path.end(), it);
            cycle.assign(idx, path.end());
            cycle.push_back(it);
            return true;
        }
    }
    path.pop_back();
    return false;
}
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
    vector<int> adj[n + 1], vis(n + 1), path, cycle;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i] && dfs(i, -1, vis, cycle, path, adj))
        {
            cout << cycle.size() << "\n";
            for (auto it : cycle)
                cout << it << " ";
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}