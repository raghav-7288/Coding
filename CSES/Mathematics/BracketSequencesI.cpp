#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9 + 7;
ll power(ll a, ll b, ll mod)
{
    a = a % mod;
    ll res = 1;
    while (b)
    {
        if (b % 2)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b = b / 2;
    }
    return res;
}
ll C(ll n, ll r)
{
    ll res = 1;
    r = min(n - r, r);
    for (ll i = 0; i < r; i++)
    {
        res = (res * (n - i)) % mod;
        res = (res * power(i + 1, mod - 2, mod)) % mod;
    }
    return res;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ll n;
    cin >> n;
    if (n & 1)
        cout << 0;
    else
    {
        n /= 2;
        cout << (C(2 * n, n) * power(n + 1, mod - 2, mod)) % mod;
    }
    return 0;
}