#include <bits/stdc++.h>
using namespace std;
int LCS(string s, int n, string t, int m, vector<vector<int>> &dp)
{
    if (!n || !m)
    {
        return dp[n][m] = 0;
    }
    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }
    if (s[n - 1] == t[m - 1])
    {
        return dp[n][m] = (1 + LCS(s, n - 1, t, m - 1, dp));
    }
    else
    {
        return dp[n][m] = (max(LCS(s, n - 1, t, m, dp), LCS(s, n, t, m - 1, dp)));
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    string str1, str2;
    cin >> str1 >> str2;
    int n = str1.length();
    int m = str2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    cout << LCS(str1, n, str2, m, dp);
    return 0;
}
// ACCGGTCGAGTGCGCGGAAGCCGGCCGAA
// GTCGTTCGGAATGCCGTTGCTCTGTAAA

// Tabulation
//  void LCS(string s, string t)
//  {
//      int n = s.length();
//      int m = t.length();
//      vector<vector<pair<int, char>>> dp(n + 1, vector<pair<int, char>>(m + 1, {0, 'n'}));
//      for (int i = 1; i <= n; i++)
//      {
//          for (int j = 1; j <= m; j++)
//          {
//              if (s[i - 1] == t[j - 1])
//              {
//                  dp[i][j] = {1 + dp[i - 1][j - 1].first, 'd'};
//              }
//              else
//              {
//                  dp[i][j].first = max(dp[i - 1][j].first, dp[i][j - 1].first);
//                  if (dp[i - 1][j].first > dp[i][j - 1].first)
//                  {
//                      dp[i][j].second = 'u';
//                  }
//                  else
//                  {
//                      dp[i][j].second = 'l';
//                  }
//              }
//          }
//      }
//      cout << dp[n][m].first << endl;
//      string lcs = "";
//      int x = n, y = m;
//      while (dp[x][y].first)
//      {
//          if (dp[x][y].second == 'd')
//          {
//              lcs += s[x - 1];
//              x--;
//              y--;
//          }
//          else if (dp[x][y].second == 'u')
//          {
//              x--;
//          }
//          else
//          {
//              y--;
//          }
//      }
//      reverse(lcs.begin(), lcs.end());
//      cout << lcs;
//  }
