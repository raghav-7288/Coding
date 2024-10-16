#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st)
{
    vis[node] = 1;
    for (auto it : adj[node])
        if (!vis[it])
            dfs(it, vis, adj, st);
    st.push(node);
}
void dfs(int node, vector<int> &vis, vector<int> adj[])
{
    vis[node] = 1;
    for (auto it : adj[node])
        if (!vis[it])
            dfs(it, vis, adj);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1], adj_r[n + 1], vis(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj_r[v].push_back(u);
    }
    stack<int> st;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i, vis, adj, st);
    }
    fill(vis.begin(), vis.end(), 0);
    int cnt = 0, start = st.top();
    while (!st.empty())
    {
        int top = st.top();
        if (!vis[top])
        {
            cnt++;
            if (cnt == 2)
            {
                cout << "NO" << endl
                     << top << " " << start;
                return 0;
            }
            dfs(top, vis, adj_r);
        }
        st.pop();
    }
    cout << "YES";
    return 0;
}