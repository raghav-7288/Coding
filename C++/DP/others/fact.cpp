#include <bits/stdc++.h>
using namespace std;
int fact(int n, vector<int> &dp)
{
    if (n == 1)
    {
        return dp[n] = 1;
    }
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = (n * fact(n - 1, dp));
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n = 5;
    vector<int> dp(n + 1, -1);
    cout << fact(n, dp);
    cout << endl;
    for (auto x : dp)
    {
        cout << x << " ";
    }
    return 0;
}