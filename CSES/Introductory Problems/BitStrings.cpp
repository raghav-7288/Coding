#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long power(long long x, long long n)
{
    x %= mod;
    long long result = 1;
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            result = (result * x) % mod;
        }
        x = (x * x) % mod;
        n /= 2;
    }
    return result;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    long long n;
    cin >> n;
    cout << power(2, n) << endl;
    return 0;
}
