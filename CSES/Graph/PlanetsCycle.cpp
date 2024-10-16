#include <bits/stdc++.h>
using namespace std;
void dfs2(int node, vector<int> &vis, vector<int> adj[], vector<int> &ans)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            ans[it] = ans[node] + 1;
            dfs2(it, vis, adj, ans);
        }
    }
}
void dfs1(int node, int d, vector<int> &tele, vector<int> &vis, vector<int> adj[], vector<int> &ans)
{
    vis[node] = 1;
    if (!vis[tele[node]])
    {
        dfs1(tele[node], d + 1, tele, vis, adj, ans);
        ans[node] = ans[tele[node]];
    }
    else
        ans[node] = d;
    dfs2(node, vis, adj, ans);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> tele(n + 1), inDeg(n + 1), adj[n + 1], ans(n + 1), vis(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> tele[i];
        inDeg[tele[i]]++;
        adj[tele[i]].push_back(i);
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (!inDeg[i])
            q.push(i);
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        if (!--inDeg[tele[node]])
            q.push(tele[node]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (inDeg[i] && !vis[i])
            dfs1(i, 1, tele, vis, adj, ans);
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    return 0;
}
