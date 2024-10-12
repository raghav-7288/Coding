#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(ll n, ll k, int mod)
{
    if (!k)
        return 1;
    if (k & 1)
        return (n * (solve(n, k - 1, mod)) % mod) % mod;
    return (solve((n * n) % mod, k / 2, mod)) % mod;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int q, mod = 1e9 + 7;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        cout << solve(a, solve(b, c, mod - 1), mod) << endl;
    }
    return 0;
}