#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> path = {n};
    queue<pair<int, int>> q;
    q.push({1, 1});
    bool found = false;
    int steps;
    vector<int> parent(n + 1, 0);
    parent[1] = -1;
    while (!q.empty())
    {
        auto [node, k] = q.front();
        q.pop();
        if (node == n)
        {
            steps = k;
            found = true;
            break;
        }
        for (auto it : adj[node])
        {
            if (parent[it])
                continue;
            parent[it] = node;
            q.push({it, k + 1});
        }
    }
    if (found)
    {
        cout << steps << endl;
        int p = n;
        while (p != 1)
        {
            p = parent[p];
            path.push_back(p);
        }
        for (auto it = path.rbegin(); it != path.rend(); it++)
            cout << *it << " ";
    }
    else
    {
        cout << "IMPOSSIBLE";
    }
    return 0;
}