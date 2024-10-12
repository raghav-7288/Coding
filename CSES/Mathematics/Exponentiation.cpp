#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9 + 7;
ll solve(ll n, ll k)
{
    if (!k)
        return 1;
    if (k & 1)
        return (n * (solve(n, k - 1)) % mod) % mod;
    return (solve((n * n) % mod, k / 2)) % mod;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        ll n, k;
        cin >> n >> k;
        cout << solve(n, k) << endl;
    }
    return 0;
}