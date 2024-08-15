#include <bits/stdc++.h>
using namespace std;
int solve(int w, int wt[], int val[], int n, vector<vector<int>> &dp)
{
    if (n == 0)
        return 0;
    if (dp[w][n] != -1)
        return dp[w][n];
    if (wt[n - 1] > w)
        return dp[w][n] = solve(w, wt, val, n - 1, dp);
    else
    {
        int pick = val[n - 1] + solve(w - wt[n - 1], wt, val, n - 1, dp);
        int notPick = solve(w, wt, val, n - 1, dp);
        return dp[w][n] = max(pick, notPick);
    }
}
// If an item can be picked any no.of times
// int solve(int w, int wt[], int val[], int n, vector<vector<int>> &dp)
// {
//     if (n == 0)
//         return 0;
//     if (dp[w][n] != -1)
//         return dp[w][n];
//     if (wt[n - 1] > w)
//         return dp[w][n] = solve(w, wt, val, n - 1, dp);
//     else
//     {
//         int pick = val[n - 1] + solve(w - wt[n - 1], wt, val, n - 1, dp);
//         int notPick = solve(w, wt, val, n - 1, dp);
//         int repeat = val[n - 1] + solve(w - wt[n - 1], wt, val, n, dp);
//         return dp[w][n] = max(repeat, max(pick, notPick));
//     }
// }
int knapSack(int w, int wt[], int val[], int n)
{
    vector<vector<int>> dp(w + 1, vector<int>(n + 1, -1));
    dp[w][n] = solve(w, wt, val, n, dp);
    return dp[w][n];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, w;
    cin >> n >> w;

    int val[n];
    int wt[n];

    for (int i = 0; i < n; i++)
        cin >> val[i];

    for (int i = 0; i < n; i++)
        cin >> wt[i];

    cout << knapSack(w, wt, val, n);
    return 0;
}