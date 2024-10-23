// 2 * (3^m)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
bool isSafe(int node, int c, vector<int> adj[], vector<int> &color)
{
    for (auto it : adj[node])
    {
        if (c == color[it])
            return false;
    }
    return true;
}
int ans = 0;
void solve(int node, int n, int m, vector<int> adj[], vector<int> &color)
{
    if (node == n)
    {
        ans++;
        return;
    }
    for (int c = 1; c <= m; c++)
    {
        if (isSafe(node, c, adj, color))
        {
            color[node] = c;
            solve(node + 1, n, m, adj, color);
            color[node] = 0;
        }
    }
}
ll mod = 1e9 + 7;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n = 4, m = 3;
    vector<int> adj[n], color(n);
    adj[0] = {1};
    adj[1] = {0, 2};
    adj[2] = {1, 3};
    adj[3] = {2, 0};
    // adj[4] = {1, 3, 5};
    // adj[5] = {4, 0};
    // adj[6] = {4, 0};
    // adj[7] = {4, 0};
    // graphColoring(adj, 3, n);
    solve(0, n, m, adj, color);
    cout << ans;
    return 0;
}