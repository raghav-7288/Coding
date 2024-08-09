#include <bits/stdc++.h>
using namespace std;
/*
Given a string.
Min no. of Deletions to make string palindrome
approach->
minDeletions = length ( s ) - length ( maxPlaindromicSubseq )
*/
int solve(int i, int j, string &s, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s[i] == s[j])
    {
        if (i == j)
            return 1 + solve(i + 1, j - 1, s, dp);
        return 2 + solve(i + 1, j - 1, s, dp);
    }
    int inc = solve(i + 1, j, s, dp);
    int dec = solve(i, j - 1, s, dp);
    return dp[i][j] = max(inc, dec);
}
int minimumNumberOfDeletions(string s)
{
    int n = s.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    // minDeletions = length ( s ) - length ( maxPlaindromicSubseq )
    return n - solve(0, n - 1, s, dp);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}