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
    vector<pair<long long, long long>> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        long long u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    vector<long long> dis(n + 1, LONG_LONG_MAX);
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    dis[1] = 0;
    pq.push({0, 1});
    while (!pq.empty())
    {
        auto [d, node] = pq.top();
        pq.pop();
        if (d > dis[node])
            continue;
        for (auto [adjNode, ew] : adj[node])
        {
            if (dis[adjNode] > d + ew)
            {
                dis[adjNode] = d + ew;
                pq.push({dis[adjNode], adjNode});
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << dis[i] << " ";
    return 0;
}