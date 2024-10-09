#include <bits/stdc++.h>
using namespace std;
int solve(int i, int t, vector<int> &coins, vector<vector<int>> &dp)
{
    if (!i)
    {
        if (t % coins[0] == 0)
            return 1;
        return 0;
    }
    if (dp[i][t] != -1)
        return dp[i][t];
    int np = solve(i - 1, t, coins, dp), p = 0;
    if (coins[i] <= t)
        p = solve(i, t - coins[i], coins, dp);
    return dp[i][t] = p + np;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, t;
    cin >> n >> t;
    int mod = 1e9 + 7;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    vector<vector<int>> dp(n, vector<int>(t + 1, 0));
    // cout << solve(n - 1, t, coins, dp);
    for (int j = 0; j <= t; j++)
    {
        if (j % coins[0] == 0)
            dp[0][j] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= t; j++)
        {
            int p = 0;
            if (coins[i] <= j)
                p = dp[i][j - coins[i]];

            dp[i][j] = (p + dp[i - 1][j]) % mod;
        }
    }
    cout << dp[n - 1][t];
    return 0;
}