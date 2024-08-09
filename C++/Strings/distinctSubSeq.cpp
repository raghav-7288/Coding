// Count All distinct Subsequences of a string
#include <bits/stdc++.h>
using namespace std;
int distinctSubsequences(string s)
{
    int n = s.size();
    int mod = 1e9 + 7;
    unordered_map<char, int> mp;
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = (2 * dp[i - 1]) % mod;
        if (mp[s[i - 1]])
        {
            dp[i] = (dp[i] - dp[mp[s[i - 1]] - 1] + mod) % mod;
        }
        mp[s[i - 1]] = i;
    }
    return dp[n];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    cout << distinctSubsequences(s);
    return 0;
}