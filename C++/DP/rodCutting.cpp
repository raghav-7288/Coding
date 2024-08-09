#include <bits/stdc++.h>
using namespace std;
int maxProfit(int len, vector<int> prices, vector<int> &dp)
{
    if (len == 0)
    {
        return dp[0] = 0;
    }
    if (dp[len] != -1)
    {
        return dp[len];
    }
    int maxPr = INT_MIN;
    for (int i = 1; i <= len; i++)
    {
        int profit = prices[i] + maxProfit(len - i, prices, dp);
        maxPr = max(maxPr, profit);
    }
    return dp[len] = maxPr;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int len;
    cin >> len;
    vector<int> prices(len + 1);
    vector<int> dp(len + 1, -1);
    for (int i = 1; i <= len; i++)
    {
        cin >> prices[i];
    }
    cout << maxProfit(len, prices, dp);
    return 0;
}