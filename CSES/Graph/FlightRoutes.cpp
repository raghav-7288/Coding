#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, long long>> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    vector<int> cnt(2e5 + 1);
    pq.push({0, 1});
    while (!pq.empty())
    {
        auto [sum, node] = pq.top();
        pq.pop();
        cnt[node]++;
        if (node == n)
        {
            cout << sum << " ";
            if (cnt[node] == k)
                return 0;
        }
        if (cnt[node] <= k)
        {
            for (auto [_node, _dis] : adj[node])
                pq.push({_dis + sum, _node});
        }
    }
    return 0;
}