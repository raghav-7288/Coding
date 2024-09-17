/*
MxN grid
return MIN path sum from 0,0 to m-1,n-1
move either down or right
*/
/*
Tabulation
vector<vector<int>> dp(m, vector<int>(n, 0));
for (int i = m - 1; i >= 0; i--)
{
    for (int j = n - 1; j >= 0; j--)
    {
        dp[i][j] = grid[i][j];
        if (i == m - 1 && j == n - 1)
        {
            continue;
        }
        else if (i == m - 1)
        {
            dp[i][j] = dp[i][j + 1] + grid[i][j];
        }
        else if (j == n - 1)
        {
            dp[i][j] = dp[i + 1][j] + grid[i][j];
        }
        else
        {
            dp[i][j] = grid[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
        }
    }
}
return dp[0][0];
*/
#include <bits/stdc++.h>
using namespace std;
int solve(int r, int c, int m, int n, vector<vector<int>> &dp, vector<vector<int>> &grid)
{
    if (r == m - 1 && c == n - 1)
        return grid[r][c];
    if (dp[r][c] != -1)
        return dp[r][c];
    int right = INT_MAX, down = INT_MAX;
    if (c + 1 < n)
        right = grid[r][c] + solve(r, c + 1, m, n, dp, grid);
    if (r + 1 < m)
        down = grid[r][c] + solve(r + 1, c, m, n, dp, grid);
    return dp[r][c] = min(right, down);
}
int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solve(0, 0, m, n, dp, grid);
}