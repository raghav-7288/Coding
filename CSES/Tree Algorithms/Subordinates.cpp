#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll mod = 1e9 + 7;
ll dfs_1(ll node, ll par, vector<ll> &subtree_count, vector<ll> adj[])
{
    ll cnt = 1;
    for (auto it : adj[node])
    {
        if (it == par)
            continue;
        cnt += dfs_1(it, node, subtree_count, adj);
    }
    return subtree_count[node] = cnt;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    ll n;
    cin >> n;
    vector<ll> adj[n + 1], subtree_count(n + 1);
    for (ll i = 2; i <= n; i++)
    {
        int u;
        cin >> u;
        adj[u].push_back(i);
    }
    dfs_1(1, 0, subtree_count, adj);
    for (ll i = 1; i <= n; i++)
    {
        cout << subtree_count[i] - 1 << " ";
    }
    return 0;
}