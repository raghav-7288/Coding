// #include <bits/stdc++.h>
// using namespace std;
// const long long INF = 1e18;
// int main()
// {
// #ifndef ONLINE_JUDGE
//     freopen("../../input.txt", "r", stdin);
//     freopen("../../output.txt", "w", stdout);
// #endif
//     int n, m;
//     cin >> n >> m;
//     vector<vector<pair<int, long long>>> adj(n + 1);
//     for (int i = 0; i < m; i++)
//     {
//         int u, v;
//         long long w;
//         cin >> u >> v >> w;
//         adj[u].push_back({v, w});
//     }
//     vector<vector<long long>> dist(n + 1, vector<long long>(2, INF));
//     priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<>> pq;
//     dist[1][0] = 0;
//     pq.push({0, {1, 0}});
//     while (!pq.empty())
//     {
//         auto [d, p] = pq.top();
//         pq.pop();
//         int node = p.first, used_coupon = p.second;
//         if (d > dist[node][used_coupon])
//             continue;
//         for (auto [adjNode, ew] : adj[node])
//         {
//             if (dist[adjNode][used_coupon] > dist[node][used_coupon] + ew)
//             {
//                 dist[adjNode][used_coupon] = dist[node][used_coupon] + ew;
//                 pq.push({dist[adjNode][used_coupon], {adjNode, used_coupon}});
//             }
//             if (!used_coupon)
//             {
//                 if (dist[adjNode][1] > dist[node][used_coupon] + ew / 2)
//                 {
//                     dist[adjNode][1] = dist[node][used_coupon] + ew / 2;
//                     pq.push({dist[adjNode][1], {adjNode, 1}});
//                 }
//             }
//         }
//     }
//     cout << min(dist[n][0], dist[n][1]);
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, long long>>> adj(n + 1), adj_r(n + 1);
    vector<tuple<int, int, long long>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj_r[v].push_back({u, w});
        edges.push_back({u, v, w});
    }
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    vector<long long> dis(n + 1, 1e18);
    dis[1] = 0;
    pq.push({0, 1});
    while (!pq.empty())
    {
        auto [d, node] = pq.top();
        pq.pop();
        if (d > dis[node])
            continue;
        for (auto it : adj[node])
        {
            if (dis[it.first] > d + it.second)
            {
                dis[it.first] = d + it.second;
                pq.push({dis[it.first], it.first});
            }
        }
    }

    vector<long long> dis_r(n + 1, 1e18);
    dis_r[n] = 0;
    pq.push({0, n});
    while (!pq.empty())
    {
        auto [d, node] = pq.top();
        pq.pop();
        if (d > dis_r[node])
            continue;
        for (auto it : adj_r[node])
        {
            if (dis_r[it.first] > d + it.second)
            {
                dis_r[it.first] = d + it.second;
                pq.push({dis_r[it.first], it.first});
            }
        }
    }

    long long ans = LONG_LONG_MAX;
    for (auto e : edges)
    {
        auto [f, t, w] = e;
        ans = min(ans, dis[f] + w / 2 + dis_r[t]);
    }
    cout << ans;
    return 0;
}
