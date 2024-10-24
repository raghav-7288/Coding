#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll mod = 1e9 + 7;
void dfs(int node, vector<int> &comp, vector<int> &vis, vector<int> adj[])
{
    vis[node] = 1;
    comp.push_back(node);
    for (auto it : adj[node])
    {
        if (!vis[it])
            dfs(it, comp, vis, adj);
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
    vector<int> adj[n + 1], vis(n + 1), inDeg(n + 1), outDeg(n + 1), comp, path;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        inDeg[v]++;
        outDeg[u]++;
    }

    dfs(1, comp, vis, adj);
    bool exist = vis[n] && (inDeg[1] + 1 == outDeg[1]) && (inDeg[n] == outDeg[n] + 1);
    for (auto node : comp)
    {
        if (node == 1 || node == n)
            continue;
        exist &= (inDeg[node] == outDeg[node]);
    }
    for (int i = 1; i <= n; i++)
    {
        if ((inDeg[i] || outDeg[i]) && !vis[i])
        {
            exist = false;
            break;
        }
    }
    if (!exist)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    stack<int> st;
    st.push(1);
    while (!st.empty())
    {
        int node = st.top();
        if (!adj[node].empty())
        {
            int it = adj[node].back();
            adj[node].pop_back();
            st.push(it);
        }
        else
        {
            path.push_back(node);
            st.pop();
        }
    }
    reverse(path.begin(), path.end());
    for (auto v : path)
        cout << v << " ";
    return 0;
}