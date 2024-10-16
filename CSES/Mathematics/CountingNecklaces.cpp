#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9 + 7;
ll power(ll a, ll b)
{
    ll res = 1;
    a %= mod;
    while (b)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ll n, m, ans = 0;
    cin >> n >> m;
    for (ll i = 0; i < n; i++)
    {
        ans = (ans + power(m, __gcd(i, n))) % mod;
    }
    ans = (ans * power(n, mod - 2)) % mod;
    cout << ans;
    return 0;
}