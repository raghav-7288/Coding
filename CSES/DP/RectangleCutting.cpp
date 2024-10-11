#include <bits/stdc++.h>
using namespace std;
int solve(int a, int b, vector<vector<int>> &dp)
{
    if (a > b)
        swap(a, b);
    if (dp[a][b] != -1)
        return dp[a][b];
    if (a == b)
        return dp[a][b] = 0;
    if (a == 1 || b == 1)
        return dp[a][b] = abs(a - b);
    int ans = INT_MAX;
    for (int i = 1; i < a; i++)
    {
        ans = min(ans, solve(i, b, dp) + solve(a - i, b, dp));
    }
    for (int i = 1; i < b; i++)
    {
        ans = min(ans, solve(a, i, dp) + solve(a, b - i, dp));
    }
    return dp[a][b] = 1 + ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int a, b;
    cin >> a >> b;
    vector<vector<int>> dp(501, vector<int>(501, -1));
    cout << solve(a, b, dp);
    return 0;
}