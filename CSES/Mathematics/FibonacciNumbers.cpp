#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll M = 1e9 + 7;
map<ll, ll> F;
ll f(ll n)
{
    if (F.count(n))
        return F[n];
    ll k = n / 2;
    if (n % 2 == 0)
    {
        return F[n] = (f(k) * f(k) + f(k - 1) * f(k - 1)) % M;
    }
    else
    {
        return F[n] = (f(k) * f(k + 1) + f(k - 1) * f(k)) % M;
    }
}
void matMul(vector<vector<ll>> &a, vector<vector<ll>> &b)
{
    vector<vector<ll>> c(2, vector<ll>(2));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                c[i][j] = (c[i][j] + (a[i][k] * b[k][j]) % M) % M;
            }
        }
    }
    a = c;
}
ll SolveUsingMatrixExponentiation(ll n)
{
    vector<vector<ll>> a(2, vector<ll>(2)), b(2, vector<ll>(2));
    a[0][0] = a[0][1] = a[1][0] = b[0][0] = b[1][1] = 1;
    while (n)
    {
        if (n & 1)
            matMul(b, a);
        matMul(a, a);
        n /= 2;
    }
    return b[0][1];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ll n;
    cin >> n;
    // F[0] = F[1] = 1;
    // cout << (n == 0 ? 0 : f(n - 1));
    cout << SolveUsingMatrixExponentiation(n);
    return 0;
}