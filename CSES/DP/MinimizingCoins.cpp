#include <bits/stdc++.h>
using namespace std;
int solve(int i, int n, int t, vector<int> &coins, vector<vector<int>> &dp)
{
    if (i == n - 1)
    {
        if (t % coins[i] == 0)
            return t / coins[i];
        return 1e9;
    }
    if (dp[i][t] != -1)
        return dp[i][t];
    int np = solve(i + 1, n, t, coins, dp);
    int p = 1e9;
    if (coins[i] <= t)
        p = 1 + solve(i, n, t - coins[i], coins, dp);
    return dp[i][t] = min(p, np);
}
int coinChange(vector<int> &coins, int tar)
{
    // int n = coins.size();
    // vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    // int ans = solve(0, n, tar, coins, dp);
    // return ans == 1e9 ? -1 : ans;

    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    for (int j = 0; j <= tar; j++)
    {
        if (j % coins[0] == 0)
            dp[0][j] = j / coins[0];
        else
            dp[0][j] = 1e9;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= tar; j++)
        {
            int p = 1e9;
            if (coins[i] <= j)
                p = 1 + dp[i][j - coins[i]];
            int np = dp[i - 1][j];
            dp[i][j] = min(p, np);
        }
    }
    return dp[n - 1][tar] == 1e9 ? -1 : dp[n - 1][tar];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, target;
    cin >> n >> target;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    cout << coinChange(coins, target);

    return 0;
}