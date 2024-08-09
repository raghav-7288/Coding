/*
all valid vowel permutations with conditions:
Each vowel 'a' may only be followed by an 'e'.
Each vowel 'e' may only be followed by an 'a' or an 'i'.
Each vowel 'i' may not be followed by another 'i'.
Each vowel 'o' may only be followed by an 'i' or a 'u'.
Each vowel 'u' may only be followed by an 'a'.
*/
#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
bool isOk(int prev, int curr)
{
    if (curr == 1)
    {
        if (prev == 2 || prev == 3 || prev == 5)
            return true;
    }
    else if (curr == 2)
    {
        if (prev == 1 || prev == 3)
            return true;
    }
    else if (curr == 3)
    {
        if (prev == 2 || prev == 4)
            return true;
    }
    else if (curr == 4)
    {
        if (prev == 3)
            return true;
    }
    else if (curr == 5)
    {
        if (prev == 3 || prev == 4)
            return true;
    }
    return false;
}
int solve(int curr, int n, vector<vector<int>> &dp)
{
    if (n == 1)
        return dp[n][curr] = 1;
    if (dp[n][curr] != -1)
        return dp[n][curr];
    long long cnt = 0;
    for (int v = 1; v <= 5; v++)
    {
        if (isOk(v, curr))
            cnt = (cnt + solve(v, n - 1, dp)) % mod;
    }
    return dp[n][curr] = cnt;
}
int countVowelPermutation(int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(6, -1));
    int ans = 0;
    for (int j = 1; j <= 5; j++)
    {
        ans = (ans + solve(j, n, dp)) % mod;
    }
    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    cout << countVowelPermutation(n);
    return 0;
}