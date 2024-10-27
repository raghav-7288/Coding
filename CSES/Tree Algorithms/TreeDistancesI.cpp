#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll mod = 1e9 + 7;
void dfs(int node, int par, int dis, int &maxDis, int &d1, vector<int> adj[])
{
    if (dis >= maxDis)
    {
        maxDis = dis;
        d1 = node;
    }
    for (auto it : adj[node])
    {
        if (it == par)
            continue;
        dfs(it, node, dis + 1, maxDis, d1, adj);
    }
}
void dfs_dis1(int node, int par, int dis, int &maxDis, int &d2, vector<int> &dis_d1, vector<int> adj[])
{
    dis_d1[node] = dis;
    if (dis >= maxDis)
    {
        maxDis = dis;
        d2 = node;
    }
    for (auto it : adj[node])
    {
        if (it == par)
            continue;
        dfs_dis1(it, node, dis + 1, maxDis, d2, dis_d1, adj);
    }
}
void dfs_dis2(int node, int par, int dis, vector<int> &dis_d2, vector<int> adj[])
{
    dis_d2[node] = dis;
    for (auto it : adj[node])
    {
        if (it == par)
            continue;
        dfs_dis2(it, node, dis + 1, dis_d2, adj);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> adj[n + 1], dis_d1(n + 1), dis_d2(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int d1, maxDis = 0;
    dfs(1, 0, 0, maxDis, d1, adj);

    int d2;
    maxDis = 0;

    dfs_dis1(d1, 0, 0, maxDis, d2, dis_d1, adj);
    dfs_dis2(d2, 0, 0, dis_d2, adj);

    for (int i = 1; i <= n; i++)
    {
        cout << max(dis_d1[i], dis_d2[i]) << " ";
    }
    return 0;
}