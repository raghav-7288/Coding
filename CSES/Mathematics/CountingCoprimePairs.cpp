#include <bits/stdc++.h>
using namespace std;
int maxi = 1e6 + 1;
vector<int> isPrime(maxi, 1), allPrimes, dp(maxi);
void seive()
{
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i * i < maxi; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j < maxi; j += i)
                isPrime[j] = 0;
        }
    }
    for (int i = 2; i < maxi; i++)
    {
        if (isPrime[i])
            allPrimes.push_back(i);
    }
}
int solve(int x)
{
    vector<int> pf;
    for (auto p : allPrimes)
    {
        if (x == 1)
            break;
        if (isPrime[x])
        {
            pf.push_back(x);
            break;
        }
        if (x % p)
            continue;
        pf.push_back(p);
        while (x % p == 0)
            x /= p;
    }
    int np = pf.size(), res = 0;
    for (int i = 0; i < (1 << np); i++)
    {
        int p = 1;
        for (int j = 0; j < np; j++)
        {
            if (i & (1 << j))
                p *= pf[j];
        }
        int prime_taken = __builtin_popcount(i);
        res += (prime_taken & 1 ? -dp[p] : dp[p]);
        dp[p]++;
    }
    return res;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    seive();
    int n;
    long long ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        ans += solve(num);
    }
    cout << ans;
    return 0;
}