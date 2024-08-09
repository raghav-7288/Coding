/*
MxN grid
return total paths from 0,0 to m-1,n-1
move either down or right
*/
// tabulation
/*
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!(i==0 && j==0)){
                    if(i==0 || j==0){
                        dp[i][j]=1;
                    }else{
                        dp[i][j]=dp[i-1][j]+dp[i][j-1];
                    }
                }
            }
        }
    return dp[m-1][n-1];
}*/
#include <bits/stdc++.h>
using namespace std;
/*
If obstacles given -->>
int solve(int r, int c, int m, int n, vector<vector<int>> &dp, vector<vector<int>> &obstacleGrid)
{
    if (r >= m || c >= n || obstacleGrid[r][c])
        return 0;
    if (r == m - 1 && c == n - 1)
        return 1;
    if (dp[r][c] != -1)
        return dp[r][c];
    int right = solve(r, c + 1, m, n, dp, obstacleGrid);
    int down = solve(r + 1, c, m, n, dp, obstacleGrid);
    return dp[r][c] = right + down;
}
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solve(0, 0, m, n, dp, obstacleGrid);
}
*/
int solve(int r, int c, int m, int n, vector<vector<int>> &dp)
{
    if (r >= m || c >= n)
        return 0;
    if (r == m - 1 && c == n - 1)
        return 1;
    if (dp[r][c] != -1)
        return dp[r][c];
    int right = solve(r, c + 1, m, n, dp);
    int down = solve(r + 1, c, m, n, dp);
    return dp[r][c] = right + down;
}
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solve(0, 0, m, n, dp);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}