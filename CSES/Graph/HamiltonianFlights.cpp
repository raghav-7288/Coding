#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll mod = 1e9 + 7;
int ans = 0;
void dfs(int node, int cnt, int n, vector<int> &vis, vector<int> adj[])
{
    vis[node] = 1;
    if (cnt == n && node == n)
    {
        ans++;
    }
    for (auto it : adj[node])
    {
        if (!vis[it])
            dfs(it, cnt + 1, n, vis, adj);
    }
    vis[node] = 0;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    // vector<int> vis(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
    }
    // TLE
    // dfs(1, 1, n, vis, adj);

    vector<vector<int>> dp(n, vector<int>(1 << n)), vis(n, vector<int>(1 << n));
    queue<pair<int, int>> q;
    dp[0][1] = 1;
    q.push({0, 1});
    vis[0][1] = 1;
    while (!q.empty())
    {
        int node = q.front().first;
        int mask = q.front().second;
        q.pop();
        if (node != n - 1)
            continue;
        for (auto it : adj[node])
        {
            int newMask = mask | (1 << it);
            if ((mask & (1 << it)) == 0)
            {
                dp[it][newMask] += dp[node][mask];
                dp[it][newMask] %= mod;
                if (!vis[it][newMask])
                {
                    q.push({it, newMask});
                    vis[it][newMask] = 1;
                }
            }
        }
    }
    cout << dp[n - 1][(1 << n) - 1];
    return 0;
}

/*

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxN = 20;
const int SIZE = 1<<maxN;
const ll MOD = 1e9+7;

int N, M;
bool inqueue[maxN][SIZE];
ll dp[maxN][SIZE];
vector<int> G[maxN];
queue<pii> Q;

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0, a, b; i < M; i++){
        scanf("%d %d", &a, &b);
        G[a-1].push_back(b-1);
    }

    dp[0][1] = 1;
    Q.push({0, 1});
    inqueue[0][1] = true;
    while(!Q.empty()){
        int u = Q.front().first;
        int mask = Q.front().second;
        Q.pop();

        if(u != N-1){
            for(int v : G[u]){
                int newMask = mask|(1<<v);
                if((mask&(1<<v)) == 0){
                    dp[v][newMask] += dp[u][mask];
                    dp[v][newMask] %= MOD;
                    if(!inqueue[v][newMask]){
                        Q.push({v, newMask});
                        inqueue[v][newMask] = true;
                    }
                }
            }
        }
    }

    printf("%lld\n", dp[N-1][(1<<N)-1]);
}

*/