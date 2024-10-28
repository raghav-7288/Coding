// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define ld long double
// ll mod = 1e9 + 7;
// ll dfs(ll node, ll par, ll d, vector<vector<ll>> &parent, vector<ll> adj[], vector<ll> &depth, vector<ll> &subTreeSum, vector<ll> &val)
// {
//     ll sum = val[node];
//     parent[node][0] = par;
//     depth[node] = d;
//     for (auto it : adj[node])
//     {
//         if (it == par)
//             continue;
//         sum += dfs(it, node, d + 1, parent, adj, depth, subTreeSum, val);
//     }
//     return subTreeSum[node] = sum;
// }
// void findParent(ll n, vector<vector<ll>> &parent)
// {
//     for (ll j = 1; j < 20; j++)
//     {
//         for (ll i = 2; i <= n; i++)
//         {
//             parent[i][j] = parent[parent[i][j - 1]][j - 1];
//         }
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
//     ll n, q;
//     cin >> n >> q;
//     vector<ll> val(n + 1), adj[n + 1], depth(n + 1), subTreeSum(n + 1);
//     vector<vector<ll>> parent(n + 1, vector<ll>(20));
//     for (ll i = 1; i <= n; i++)
//     {
//         cin >> val[i];
//     }
//     for (ll i = 1; i < n; i++)
//     {
//         ll u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     dfs(1, 0, 0, parent, adj, depth, subTreeSum, val);
//     findParent(n, parent);
//     while (q--)
//     {
//         ll t, s;
//         cin >> t >> s;
//         if (t == 1)
//         {
//             ll x;
//             cin >> x;
//             ll diff = x - val[s];
//             val[s] = x;
//             while (s)
//             {
//                 subTreeSum[s] += diff;
//                 s = parent[s][0];
//             }
//         }
//         else
//         {
//             cout << subTreeSum[s] << " ";
//         }
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
typedef long long ll;

int N, Q;
vector<int> adj[MAXN];
int tin[MAXN], tout[MAXN], timer = 0;
int order[MAXN]; // Map time to node
ll vals[MAXN];
ll tree[4 * MAXN]; // Segment tree
void dfs(int u, int p)
{
    tin[u] = ++timer;
    order[tin[u]] = u;
    for (int v : adj[u])
    {
        if (v != p)
        {
            dfs(v, u);
        }
    }
    tout[u] = timer;
}
void build(int node, int l, int r)
{
    if (l == r)
    {
        tree[node] = vals[order[l]];
    }
    else
    {
        int mid = (l + r) / 2;
        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}
void update(int node, int l, int r, int pos, ll val)
{
    if (l == r)
    {
        tree[node] = val;
    }
    else
    {
        int mid = (l + r) / 2;
        if (pos <= mid)
            update(2 * node, l, mid, pos, val);
        else
            update(2 * node + 1, mid + 1, r, pos, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}
ll query(int node, int l, int r, int ql, int qr)
{
    if (qr < l || r < ql)
        return 0;
    if (ql <= l && r <= qr)
        return tree[node];
    int mid = (l + r) / 2;
    return query(2 * node, l, mid, ql, qr) + query(2 * node + 1, mid + 1, r, ql, qr);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i)
        cin >> vals[i];
    for (int i = 0; i < N - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    build(1, 1, N);
    while (Q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int u;
            ll x;
            cin >> u >> x;
            update(1, 1, N, tin[u], x);
        }
        else
        {
            int u;
            cin >> u;
            ll res = query(1, 1, N, tin[u], tout[u]);
            cout << res << " ";
        }
    }
    return 0;
}
