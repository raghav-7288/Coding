#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int solve(int r, int c, int n, vector<vector<char>> &grid, vector<vector<int>> &dp)
{
    if (r >= n || c >= n || grid[r][c] == '*')
        return 0;
    if (r == n - 1 && c == n - 1)
        return 1;
    if (dp[r][c] != -1)
        return dp[r][c];
    int right = solve(r, c + 1, n, grid, dp), down = solve(r + 1, c, n, grid, dp);
    return dp[r][c] = (right + down) % mod;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << solve(0, 0, n, grid, dp);
    return 0;
}