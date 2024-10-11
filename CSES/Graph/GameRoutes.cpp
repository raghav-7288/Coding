#include <bits/stdc++.h>
using namespace std;
// long long ans = 0;
// void dfs(int node, int n, vector<int> &vis, vector<int> adj[])
// {
//     if (node == n)
//     {
//         ans++;
//         return;
//     }
//     vis[node] = 1;
//     for (auto it : adj[node])
//     {
//         if (!vis[it])
//             dfs(it, n, vis, adj);
//     }
//     vis[node] = 0;
// }
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, m, mod = 1e9 + 7;
    cin >> n >> m;
    vector<int> adj[n + 1], vis(n + 1), inDeg(n + 1), cnt(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        inDeg[v]++;
    }
    cnt[1] = 1;
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
            cnt[it] = (cnt[it] + cnt[u]) % mod;
            if (!--inDeg[it])
                q.push(it);
        }
    }
    cout << cnt[n];
    return 0;
}