#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll mod = 1e9 + 7;
int flip(int x)
{
    if (x & 1)
        return x + 1;
    return x - 1;
}
void dfs1(int node, vector<int> &vis, vector<int> adj[], vector<int> &order)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
            dfs1(it, vis, adj, order);
    }
    order.push_back(node);
}
void dfs2(int node, int c, vector<int> adj[], vector<int> &vis, vector<int> &cid)
{
    vis[node] = 1;
    cid[node] = c;
    for (auto it : adj[node])
    {
        if (!vis[it])
            dfs2(it, c, adj, vis, cid);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<int> adj[2 * m + 1], adj_r[2 * m + 1];
    for (int i = 0; i < n; i++)
    {
        char c1, c2;
        int t1, t2;
        cin >> c1 >> t1 >> c2 >> t2;

        int a = 2 * t1 - (c1 == '-');
        int b = 2 * t2 - (c2 == '-');

        adj[flip(a)].push_back(b);
        adj[flip(b)].push_back(a);

        adj_r[b].push_back(flip(a));
        adj_r[a].push_back(flip(b));
    }

    vector<int> order, vis(2 * m + 1, 0), cid(2 * m + 1, 0);
    for (int i = 1; i <= 2 * m; i++)
    {
        if (!vis[i])
            dfs1(i, vis, adj, order);
    }

    fill(vis.begin(), vis.end(), 0);
    int c = 0;
    reverse(order.begin(), order.end());
    for (auto node : order)
    {
        if (!vis[node])
            dfs2(node, ++c, adj_r, vis, cid);
    }

    for (int i = 1; i <= m; i++)
    {
        if (cid[2 * i - 1] == cid[2 * i])
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    vector<char> ans(m + 1);
    for (int i = 1; i <= m; i++)
    {
        if (cid[2 * i] > cid[2 * i - 1])
            ans[i] = '+';
        else
            ans[i] = '-';
    }

    for (int i = 1; i <= m; i++)
        cout << ans[i];
    return 0;
}
