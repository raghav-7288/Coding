/*
MxN grid
start from row 0
return min sum of ANY falling path
(r, c)->(r + 1, c - 1)OR(r + 1, c)OR(r + 1, c + 1).
*/

/*
Tabulation
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(i==0){ dp[i][j]=matrix[i][j];}
        else{
            int l=INT_MAX,ri=INT_MAX,d;
            d=dp[i-1][j];
            if(j>0) l=dp[i-1][j-1];
            if(j<m-1) ri=dp[i-1][j+1];
            dp[i][j]=matrix[i][j] + min({l,d,ri});
        }
    }
}
int ans=INT_MAX;
for(int j=0;j<m;j++) ans=min(ans,dp[n-1][j]);
return ans;
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
    if (c > 0)
        left = solve(r + 1, c - 1, m, n, mat, dp);
    down = solve(r + 1, c, m, n, mat, dp);
    if (c < n - 1)
        right = solve(r + 1, c + 1, m, n, mat, dp);
    return dp[r][c] = mat[r][c] + min(down, min(left, right));
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