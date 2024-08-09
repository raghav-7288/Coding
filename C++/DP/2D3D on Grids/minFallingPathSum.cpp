/*
MxN grid
start from row 0
return min sum of ANY falling path
(r, c)->(r + 1, c - 1)OR(r + 1, c)OR(r + 1, c + 1).
*/
#include <bits/stdc++.h>
using namespace std;
int solve(int r, int c, int m, int n, vector<vector<int>> &mat, vector<vector<int>> &dp)
{
    if (r == m - 1)
        return mat[r][c];
    if (dp[r][c] != -1)
        return dp[r][c];
    int left = INT_MAX, right = INT_MAX, down = INT_MAX;
    int val = mat[r][c];
    if (c > 0)
        left = solve(r + 1, c - 1, m, n, mat, dp);
    down = solve(r + 1, c, m, n, mat, dp);
    if (c < n - 1)
        right = solve(r + 1, c + 1, m, n, mat, dp);
    return dp[r][c] = val + min(down, min(left, right));
}
int minFallingPathSum(vector<vector<int>> &mat)
{
    int ans = INT_MAX, m = mat.size(), n = mat[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, solve(0, i, m, n, mat, dp));
    }
    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}