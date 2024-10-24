// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define ld long double
// ll mod = 1e9 + 7;
// bool kuhns(int node, vector<int> &vis, vector<int> adj[], vector<int> &matching)
// {
//     if (vis[node])
//         return false;
//     vis[node] = 1;
//     for (auto it : adj[node])
//     {
//         if (matching[it] == -1 || kuhns(matching[it], vis, adj, matching))
//         {
//             matching[it] = node;
//             return true;
//         }
//     }
//     return false;
// }
// int main()
// {
// #ifndef ONLINE_JUDGE
//     freopen("../input.txt", "r", stdin);
//     freopen("../output.txt", "w", stdout);
// #endif

//     int n, m, k;
//     cin >> n >> m >> k;

//     vector<int> adj[m + 1];
//     vector<int> matching(n + 1, -1);
//     for (int i = 0; i < k; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         adj[v].push_back(u);
//     }
//     for (int i = 1; i <= m; i++)
//     {
//         vector<int> vis(m + 1, 0);
//         kuhns(i, vis, adj, matching);
//     }
//     vector<pair<int, int>> pairs;
//     for (int i = 1; i <= n; i++)
//     {
//         if (matching[i] != -1)
//         {
//             pairs.push_back({matching[i], i});
//         }
//     }
//     cout << pairs.size() << endl;
//     for (auto p : pairs)
//     {
//         cout << p.first << " " << p.second << endl;
//     }
//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
const int maxN = 505;

bool used[maxN];
int N, M, K, cnt, mt[maxN];
vector<int> G[maxN];
vector<pii> pairs;

bool kuhns(int u)
{
    if (used[u])
        return false;

    used[u] = true;
    for (int v : G[u])
    {
        if (!mt[v] || kuhns(mt[v]))
        {
            mt[v] = u;
            return true;
        }
    }

    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0, a, b; i < K; i++)
    {
        scanf("%d %d", &a, &b);
        G[b].push_back(a);
    }

    for (int i = 1; i <= M; i++)
    {
        fill(used + 1, used + N + 1, false);
        kuhns(i);
    }

    cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        if (mt[i])
        {
            pairs.push_back({i, mt[i]});
            cnt++;
        }
    }

    printf("%d\n", cnt);
    for (pii P : pairs)
        printf("%d %d\n", P.first, P.second);
}