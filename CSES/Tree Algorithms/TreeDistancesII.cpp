#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll mod = 1e9 + 7;
ll dfs_1(ll node, ll par, ll dis, ll &sum_for_1, vector<ll> &subtree_count, vector<ll> adj[])
{
    ll cnt = 1;
    sum_for_1 += dis;
    for (auto it : adj[node])
    {
        if (it == par)
            continue;
        cnt += dfs_1(it, node, dis + 1, sum_for_1, subtree_count, adj);
    }
    return subtree_count[node] = cnt;
}
void dfs_shift(ll node, ll par, vector<ll> &subtree_count, vector<ll> &ans, vector<ll> adj[])
{
    for (auto it : adj[node])
    {
        if (it == par)
            continue;
        ans[it] = ans[node] + subtree_count[1] - 2 * subtree_count[it];
        dfs_shift(it, node, subtree_count, ans, adj);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    ll n;
    cin >> n;
    vector<ll> adj[n + 1], subtree_count(n + 1), ans(n + 1);
    for (ll i = 1; i < n; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll sum_for_1 = 0;
    dfs_1(1, 0, 0, sum_for_1, subtree_count, adj);
    ans[1] = sum_for_1;
    dfs_shift(1, 0, subtree_count, ans, adj);
    for (ll i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}