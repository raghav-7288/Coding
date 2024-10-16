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
    ll n, o = 0, c = 0;
    cin >> n;
    string s;
    cin >> s;
    ll m = s.length();
    for (auto ch : s)
    {
        if (ch == '(')
            o++;
        else
            c++;
        if (c > o)
        {
            cout << 0;
            return 0;
        }
    }
    if (n == m || o == n / 2)
    {
        cout << 1;
        return 0;
    }
    if (n & 1 || o > n / 2)
    {
        cout << 0;
        return 0;
    }
    cout << ((C(n - m, n / 2 - o) - C(n - m, n / 2 - o - 1)) % mod + mod) % mod;
    return 0;
}