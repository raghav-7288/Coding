/*
There is a robot on an m x n grid.
The robot is initially located at the top-left corner (i.e., grid[0][0]).
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]).
The robot can only move either down or right at any point in time.
Given the two integers m and n, return the number of possible unique paths
that the robot can take to reach the bottom-right corner.
*/
#include <bits/stdc++.h>
using namespace std;
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

// If given an obstacle grid
// An obstacle and space are marked as 1 or 0 respectively in grid.
// A path that the robot takes cannot include any square that is an obstacle.
//  int solve(int r,int c,int m,int n,vector<vector<int>> &dp,vector<vector<int>>& obstacleGrid){
//      if(r>=m || c>=n || obstacleGrid[r][c]) return 0;
//      if(r==m-1 && c==n-1) return 1;
//      if(dp[r][c]!=-1) return dp[r][c];
//      int right=solve(r,c+1,m,n,dp,obstacleGrid);
//      int down=solve(r+1,c,m,n,dp,obstacleGrid);
//      return dp[r][c]=right+down;
//  }

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