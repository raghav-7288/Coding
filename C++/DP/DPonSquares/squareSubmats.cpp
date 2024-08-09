/*
1277.Given a m * n matrix of ones and zeros,
return how many square submatrices have all ones.
dp[i][j] = no. of squares ending on i,j
1st row 1st col as it is
dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
*/
#include <bits/stdc++.h>
using namespace std;
int countSquares(vector<vector<int>> &matrix)
{
    vector<vector<int>> dp(matrix);
    int r = matrix.size(), c = matrix[0].size();
    int ans = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i && j && matrix[i][j])
            {
                dp[i][j] += min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            }
            ans += dp[i][j];
        }
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