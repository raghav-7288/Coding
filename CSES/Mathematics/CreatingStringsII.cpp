#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> dp(1e6 + 1, -1);
int m = 1e9 + 7;
ll power(ll a, ll b, ll mod = 1e9 + 7)
{
    ll res = 1;
    a %= mod;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
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
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    ll n = s.length();
    map<char, ll> mp;
    for (auto c : s)
        mp[c]++;
    ll ans = factorial(n);
    for (auto _m : mp)
    {
        if (_m.second > 1)
        {
            ans = (ans * inverseFactorial(_m.second)) % m;
        }
    }
    cout << ans;
    return 0;
}