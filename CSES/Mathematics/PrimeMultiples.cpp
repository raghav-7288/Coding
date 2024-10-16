#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ll n, k, ans = 0, p, c;
    cin >> n >> k;
    vector<ll> primes(k);
    for (int i = 0; i < k; i++)
    {
        cin >> primes[i];
    }
    for (int i = 1; i < (1 << k); i++)
    {
        p = 1;
        c = 0;
        for (int j = 0; j < k; j++)
        {
            if (i & (1LL << j))
            {
                if (p > (n / primes[j]))
                {
                    p = n + 1;
                    break;
                }
                p *= primes[j];
                c++;
            }
        }
        ans += (n / p) * ((c & 1) ? 1 : -1);
    }
    cout << ans;
    return 0;
}