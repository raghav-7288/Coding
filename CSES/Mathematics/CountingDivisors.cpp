#include <bits/stdc++.h>
using namespace std;
vector<int> seive()
{
    vector<int> isPrime(1e6 + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i * i <= 1e6; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= 1e6; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }
    vector<int> primes;
    for (int i = 2; i <= 1e6; i++)
        if (isPrime[i])
            primes.push_back(i);
    return primes;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    vector<int> primes = seive();
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        int ans = 1;
        for (int p : primes)
        {
            if (p * p > n)
                break;
            int cnt = 0;
            while (n % p == 0)
            {
                cnt++;
                n /= p;
            }
            ans *= (cnt + 1);
        }
        if (n > 1)
            ans *= 2;

        cout << ans << endl;
    }
    return 0;
}