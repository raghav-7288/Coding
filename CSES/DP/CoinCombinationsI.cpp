#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int solve(int n, int t, vector<int> &coins, vector<int> &dp)
{
    if (!t)
        return 1;
    if (t < 0)
        return 0;
    if (dp[t] != -1)
        return dp[t];
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = (ans + solve(n, t - coins[i], coins, dp)) % mod;
    return dp[t] = ans % mod;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, t;
    cin >> n >> t;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    vector<int> dp(t + 1, 0);
    dp[0] = 1;
    // cout << solve(n, t, coins, dp);
    for (int j = 1; j <= t; j++)
    {
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (j - coins[i] >= 0)
                ans += dp[j - coins[i]];
        }
        dp[j] = ans % mod;
    }
    cout << dp[t];
    return 0;
}