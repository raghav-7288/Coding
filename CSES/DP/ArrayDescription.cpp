#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, m, mod = 1e9 + 7;
    cin >> n >> m;
    vector<int> arr(n);
    for (auto &x : arr)
        cin >> x;

    vector<vector<ll>> dp(n, vector<ll>(m + 2, 0));
    for (int i = 0; i < n; i++)
    {
        if (!i)
        {
            if (!arr[i])
            {
                for (int j = 1; j <= m; j++)
                {
                    dp[i][j] = 1;
                }
            }
            else
                dp[i][arr[i]] = 1;
        }
        else
        {
            if (!arr[i])
            {
                for (int j = 1; j <= m; j++)
                {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % mod;
                }
            }
            else
                dp[i][arr[i]] = (dp[i - 1][arr[i] - 1] + dp[i - 1][arr[i]] + dp[i - 1][arr[i] + 1]) % mod;
        }
    }

    long long ans = 0;
    for (int val = 1; val <= m; val++)
    {
        ans = (ans + dp[n - 1][val]) % mod;
    }
    cout << ans;
    return 0;
}