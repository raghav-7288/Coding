#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m, mod = 1e9 + 7;
vector<ll> ways, cost, minF, maxF;

struct Comparator
{
    bool operator()(int x, int y) const
    {
        return cost[x] == cost[y] ? x < y : cost[x] < cost[y];
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> n >> m;
    ways.resize(n + 1);
    cost.assign(n + 1, 1e18);
    minF.assign(n + 1, 1e9);
    maxF.assign(n + 1, 0);

    vector<pair<int, ll>> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
    }

    set<int, Comparator> st;

    st.insert(1);
    ways[1] = 1;
    cost[1] = 0;
    minF[1] = maxF[1] = 0;

    while (!st.empty())
    {
        int node = *st.begin();
        ll d = cost[node];
        st.erase(st.begin());

        for (auto [adjNode, ew] : adj[node])
        {
            int v = adjNode;
            ll w = ew;
            if (d + w <= cost[v])
            {
                st.erase(v);

                if (d + w == cost[v])
                {
                    ways[v] = (ways[node] + ways[v]) % mod;
                    minF[v] = min(minF[v], minF[node] + 1);
                    maxF[v] = max(maxF[v], maxF[node] + 1);
                }
                if (d + w < cost[v])
                {
                    cost[v] = d + w;
                    ways[v] = ways[node];
                    minF[v] = minF[node] + 1;
                    maxF[v] = maxF[node] + 1;
                }
                st.insert(v);
            }
        }
    }

    cout << cost[n] << " " << ways[n] << " " << minF[n] << " " << maxF[n];
    return 0;
}
