#include <bits/stdc++.h>
using namespace std;
int solve(int i, int n, int x, vector<int> &cost, vector<int> &pages, vector<vector<int>> &dp)
{
    if (i == n)
        return 0;
    if (dp[i][x] != -1)
        return dp[i][x];
    int np = solve(i + 1, n, x, cost, pages, dp), p = 0;
    if (cost[i] <= x)
        p = pages[i] + solve(i + 1, n, x - cost[i], cost, pages, dp);
    return dp[i][x] = max(p, np);
}
int bs(int n, int x, vector<int> &cost, vector<int> &pages)
{
    // vector<vector<int>> dp(n, vector<int>(x + 1, -1));
    // return solve(0, n, x, cost, pages, dp);
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    for (int i = 0; i <= x; i++)
    {
        dp[n][i] = 0;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 1; j <= x; j++)
        {
            int np = dp[i + 1][j], p = 0;
            if (cost[i] <= j)
                p = pages[i] + dp[i + 1][j - cost[i]];
            dp[i][j] = max(p, np);
        }
    }
    return dp[0][x];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, x;
    cin >> n >> x;
    vector<int> cost(n), pages(n);
    for (int i = 0; i < n; i++)
        cin >> cost[i];
    for (int i = 0; i < n; i++)
        cin >> pages[i];
    cout << bs(n, x, cost, pages);
    return 0;
}