#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9 + 7, maxi = 1e6 + 1;
vector<ll> dp(maxi, -1);
ll D(ll n)
{
    if (n == 1 || n == 2)
        return dp[n] = n - 1;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = ((n - 1) * ((D(n - 1) + D(n - 2)) % mod)) % mod;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ll n;
    cin >> n;
    cout << D(n);
    return 0;
}