#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<ll> x(n), k(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> k[i];
    }
    ll numOfDiv = 1, sumOfDiv = 0, productOfDivisor = 1, mod = 1e9 + 7;

    for (auto power : k)
    {
        numOfDiv = (numOfDiv * (power + 1)) % mod;
    }

    return 0;
}