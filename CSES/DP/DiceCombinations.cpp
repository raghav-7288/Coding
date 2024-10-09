#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int solve(int t, vector<int> &dp)
{
    if (!t)
        return 1;
    if (t < 0)
        return 0;
    if (dp[t] != -1)
        return dp[t];
    int ans = 0;
    for (int i = 1; i <= 6; i++)
    {
        ans = (ans + solve(t - i, dp)) % mod;
    }
    return dp[t] = ans % mod;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    vector<int> dp(t + 1, -1);
    cout << solve(t, dp);
    return 0;
}