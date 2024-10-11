#include <bits/stdc++.h>
using namespace std;
// Function to compute (a^b) % mod using binary exponentiation
long long power(long long a, long long b, int mod)
{
    long long result = 1;
    a %= mod;
    while (b > 0)
    {
        if (b % 2 == 1)
            result = result * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return result;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, mod = 1e9 + 7;
    cin >> n;
    if (n % 4 == 1 || n % 4 == 2)
    {
        cout << 0;
        return 0;
    }
    long long total_sum = n * (n + 1LL) / 2;
    if (n % 4 == 1 || n % 4 == 2 || total_sum % 2 != 0)
    {
        cout << 0;
        return 0;
    }

    long long target = total_sum / 2;
    vector<long long> dp(target + 1, 0);
    dp[0] = 1;
    for (int num = 1; num <= n; num++)
    {
        for (long long s = target; s >= num; s--)
        {
            dp[s] = (dp[s] + dp[s - num]) % mod;
        }
    }
    cout << dp[target] * power(2, mod - 2, mod) % mod;

    return 0;
}
