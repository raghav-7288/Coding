#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll m = 1e9 + 7;
vector<ll> dp(1e6 + 1, -1);
ll power(ll n, ll k)
{
    if (!k)
        return 1;
    if (k & 1)
        return (n * (power(n, k - 1)) % m) % m;
    return (power((n * n) % m, k / 2)) % m;
}
// ll power(ll a, ll b, ll mod = 1e9 + 7)
// {
//     ll res = 1;
//     a %= mod;
//     while (b > 0)
//     {
//         if (b & 1)
//             res = res * a % mod;
//         a = a * a % mod;
//         b >>= 1;
//     }
//     return res;
// }
ll factorial(ll n)
{
    if (n <= 1)
        return dp[n] = 1;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = (n * factorial(n - 1)) % m;
}
ll inverseFactorial(ll n)
{
    return power(factorial(n), m - 2);
}
ll ncr(ll n, ll r)
{
    if (r > n)
        return 0;
    ll num = factorial(n);
    ll denom = (inverseFactorial(r) * inverseFactorial(n - r)) % m;
    return (num * denom) % m;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        ll n, r;
        cin >> n >> r;
        cout << ncr(n, r) << endl;
    }
    return 0;
}