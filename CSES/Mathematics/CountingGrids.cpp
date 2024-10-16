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
    ll n;
    cin >> n;
    ll a = n * n, b = (a + 3 * (n & 1)) / 4, c = (a + (n & 1)) / 2;
    cout << ((power(2, a) + 2 * power(2, b) + power(2, c)) * power(4, mod - 2)) % mod;
    return 0;
}