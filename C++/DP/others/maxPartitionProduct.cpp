// partion n into k>=2 parts such that product of partition is maximum
#include <bits/stdc++.h>
using namespace std;
int solve(int n, vector<int> &dp)
{
    if (n == 2)
    {
        return dp[2] = 1;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        int p = i * max(n - i, solve(n - i, dp));
        ans = max(ans, p);
    }
    return dp[n] = ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    dp[1] = 1;
    int ans = INT_MIN;
    cout << solve(n, dp);
}