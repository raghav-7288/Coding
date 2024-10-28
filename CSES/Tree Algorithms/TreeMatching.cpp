// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define ld long double
// ll mod = 1e9 + 7;
// void dfs(int node, int par, vector<vector<ll>> &matching, vector<ll> adj[])
// {
//     for (auto it : adj[node])
//     {
//         if (it == par)
//             continue;
//         dfs(it, node, matching, adj);
//         matching[node][0] += max(matching[it][0], matching[it][1]);
//     }
//     for (auto it : adj[node])
//     {
//         if (it == par)
//             continue;
//         matching[node][1] = max(matching[node][1], matching[it][0] + 1 + matching[node][0] - max(matching[it][0], matching[it][1]));
//     }
// }
// int main()
// {
// #ifndef ONLINE_JUDGE
//     freopen("../../input.txt", "r", stdin);
//     freopen("../../output.txt", "w", stdout);
// #endif
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
// ll n;
// cin >> n;
// vector<ll> adj[n + 1];
// vector<vector<ll>> matching(n + 1, vector<ll>(2));
// for (ll i = 1; i < n; i++)
// {
//     int u, v;
//     cin >> u >> v;
//     adj[u].push_back(v);
//     adj[v].push_back(u);
// }
//     dfs(1, 0, matching, adj);
//     cout << max(matching[1][0], matching[1][1]);
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll mod = 1e9 + 7;
void dfs(ll node, ll par, ll &ans, vector<ll> &picked, vector<ll> adj[])
{
    for (auto it : adj[node])
    {
        if (it == par)
            continue;
        dfs(it, node, ans, picked, adj);
        if (!picked[node] && !picked[it])
        {
            picked[node] = picked[it] = 1;
            ans++;
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, ans = 0;
    cin >> n;
    vector<ll> adj[n + 1], picked(n + 1);
    for (ll i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0, ans, picked, adj);
    cout << ans;
    return 0;
}