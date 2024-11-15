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
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> adj[n + 1];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int d1, maxDis = 0;
    dfs(1, 0, 0, maxDis, d1, adj);
    maxDis = 0;
    dfs(d1, 0, 0, maxDis, d1, adj);
    cout << maxDis;
    return 0;
}