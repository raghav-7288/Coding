#include <bits/stdc++.h>
using namespace std;

int fibonacci(vector<int> &dp, int n)
{
        if (n == 0 || n == 1)
        {
                dp[n] = 1;
                return 1;
        }
        if (dp[n] != -1)
        {
                cout<<"yes"<<n;
                return dp[n];
        }
        dp[n] = fibonacci(dp, n - 1) + fibonacci(dp, n - 2);
        return dp[n];
}
int main()
{
#ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
#endif
        int n = 5;
        vector<int> dp(n, -1);
        fibonacci(dp, n - 1);
        for (auto x : dp)
        {
                cout << x << " ";
        }
        

        // cout << endl
        //      << dp.size();
        return 0;
}