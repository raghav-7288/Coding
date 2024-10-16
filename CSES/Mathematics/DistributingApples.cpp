#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll maxNum = 2 * 1e6 + 1;
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
        res = (res * 1LL * (n - i)) % mod;
        res = (res * 1LL * power(i + 1, mod - 2, mod)) % mod;
    }
    return res;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ll n, m;
    cin >> n >> m;
    cout << C(n + m - 1, m);
    return 0;
}