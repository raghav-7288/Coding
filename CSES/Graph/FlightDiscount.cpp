#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, long long>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    vector<vector<long long>> dist(n + 1, vector<long long>(2, INF));
    priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<>> pq;
    dist[1][0] = 0;
    pq.push({0, {1, 0}});
    while (!pq.empty())
    {
        auto [d, p] = pq.top();
        pq.pop();
        int node = p.first, used_coupon = p.second;
        if (d > dist[node][used_coupon])
            continue;
        for (auto [adjNode, ew] : adj[node])
        {
            if (dist[adjNode][used_coupon] > dist[node][used_coupon] + ew)
            {
                dist[adjNode][used_coupon] = dist[node][used_coupon] + ew;
                pq.push({dist[adjNode][used_coupon], {adjNode, used_coupon}});
            }
            if (!used_coupon)
            {
                if (dist[adjNode][1] > dist[node][used_coupon] + ew / 2)
                {
                    dist[adjNode][1] = dist[node][used_coupon] + ew / 2;
                    pq.push({dist[adjNode][1], {adjNode, 1}});
                }
            }
        }
    }
    cout << min(dist[n][0], dist[n][1]);
    return 0;
}
