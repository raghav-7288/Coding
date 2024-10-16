#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9 + 7;
void matMul(vector<vector<ll>> &a, vector<vector<ll>> &b)
{
    vector<vector<ll>> c(6, vector<ll>(6));
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            for (int k = 0; k < 6; k++)
            {
                c[i][j] = (c[i][j] + (a[i][k] * b[k][j]) % mod) % mod;
            }
        }
    }
    a = c;
}
ll waysToGetSumNFromDice(ll n)
{
    vector<vector<ll>> a(6, vector<ll>(6)), b(6, vector<ll>(6));
    for (int i = 0; i < 6; i++)
    {
        a[0][i] = 1;
        if (i < 5)
        {
            a[i + 1][i] = 1;
        }
        b[i][i] = 1;
    }
    while (n)
    {
        if (n & 1)
            matMul(b, a);
        matMul(a, a);
        n /= 2;
    }
    return b[0][0];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ll n;
    cin >> n;
    cout << waysToGetSumNFromDice(n);
    return 0;
}