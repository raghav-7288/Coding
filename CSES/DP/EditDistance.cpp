#include <bits/stdc++.h>
using namespace std;
int solve(int i, int j, string s, string t, vector<vector<int>> &dp)
{
    if (!i)
        return j;
    if (!j)
        return i;
    if (dp[i - 1][j - 1] != -1)
        return dp[i - 1][j - 1];
    if (s[i - 1] == t[j - 1])
        return solve(i - 1, j - 1, s, t, dp);
    int replace = solve(i - 1, j - 1, s, t, dp);
    int insert = solve(i, j - 1, s, t, dp);
    int remove = solve(i - 1, j, s, t, dp);
    return dp[i - 1][j - 1] = 1 + min({replace, insert, remove});
}
int minDistance(string s, string t)
{
    int n = s.length();
    int m = t.length();

    // vector<vector<int>> dp(n, vector<int>(m, -1));
    // return solve(n, m, s, t, dp);

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
        dp[i][0] = i;
    for (int j = 0; j <= m; j++)
        dp[0][j] = j;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]});
        }
    }
    return dp[n][m];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    string s, t;
    cin >> s >> t;
    cout << minDistance(s, t);
    return 0;
}