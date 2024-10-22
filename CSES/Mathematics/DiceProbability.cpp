#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9 + 7;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, a, b;
    cin >> n >> a >> b;
    vector<vector<double>> dp(n + 1, vector<double>(6 * n + 1, 0));
    dp[0][0] = 1.0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 6 * n; j++)
        {
            for (int k = 1; k <= 6; k++)
            {
                if (j >= k)
                {
                    dp[i][j] += dp[i - 1][j - k] / 6.0;
                }
            }
        }
    }
    double sum = 0;
    for (int i = a; i <= b; i++)
    {
        sum += dp[n][i];
    }
    cout << fixed << setprecision(6) << sum;
    return 0;
}
