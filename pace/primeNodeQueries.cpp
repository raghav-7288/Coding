#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll mod = 1e9 + 7;
vector<int> seive()
{
    vector<int> isPrime(1e5 + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i * i <= 1e5; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= 1e5; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }
    return isPrime;
}
int dfs(int node, int par, vector<int> adj[], vector<int> &values, vector<int> &cntPrimes)
{
    int cnt = values[node];
    for (auto it : adj[node])
    {
        if (it == par)
            continue;
        cnt += dfs(it, node, adj, values, cntPrimes);
    }
    return cntPrimes[node] = cnt;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    vector<int> isPrime = seive();
    int n;
    cin >> n;
    vector<int> adj[n + 1], values(n + 1, 0), cntPrimes(n + 1, 0), vis(n + 1, 0);
    vector<int> first, second;
    for (int i = 1; i <= n - 1; i++)
    {
        int u;
        cin >> u;
        first.push_back(u);
    }
    for (int i = 1; i <= n - 1; i++)
    {
        int u;
        cin >> u;
        second.push_back(u);
    }
    for (int i = 0; i < n - 1; i++)
    {
        adj[first[i]].push_back(second[i]);
        adj[second[i]].push_back(first[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        int v;
        cin >> v;
        if (isPrime[v])
            values[i] = 1;
    }
    dfs(1, -1, adj, values, cntPrimes);
    int nq;
    cin >> nq;
    while (nq--)
    {
        int node;
        cin >> node;
        cout << cntPrimes[node] << endl;
    }
    return 0;
}
