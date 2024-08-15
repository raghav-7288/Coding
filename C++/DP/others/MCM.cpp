#include <bits/stdc++.h>
using namespace std;
int MCM(int i, int j, vector<int> &ord, vector<vector<int>> &dp)
{
    if (i == j)
    {
        return dp[i - 1][j - 1] = 0;
    }
    if (dp[i - 1][j - 1] != -1)
    {
        return dp[i - 1][j - 1];
    }
    int ans = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        ans = min(ans, MCM(i, k, ord, dp) + MCM(k + 1, j, ord, dp) + ord[i - 1] * ord[k] * ord[j]);
    }
    return dp[i - 1][j - 1] = ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> ord;
    vector<vector<int>> dp(n + 1, vector<int>(n, -1));
    for (int i = 0; i <= n; i++)
    {
        int x;
        cin >> x;
        ord.push_back(x);
    }
    cout << MCM(1, n, ord, dp);
    return 0;
}

// Tabulation
//  int MatrixChainOrder(int p[], int n)
//  {
//      int m[n][n];
//      int i, j, k, L, q;
//      for (i = 1; i < n; i++)
//          m[i][i] = 0;
//      for (L = 2; L < n; L++)
//      {
//          for (i = 1; i < n - L + 1; i++)
//          {
//              j = i + L - 1;
//              m[i][j] = INT_MAX;
//              for (k = i; k <= j - 1; k++)
//              {
//                  q = m[i][k] + m[k + 1][j]
//                      + p[i - 1] * p[k] * p[j];
//                  if (q < m[i][j])
//                      m[i][j] = q;
//              }
//          }
//      }
//      return m[1][n - 1];
//  }