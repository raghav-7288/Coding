#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (long long k = 1; k <= n; k++)
    {
        long long p = pow(k, 2);
        cout << p * (p - 1) / 2 - 4 * (k - 1) * (k - 2) << endl;
    }
    return 0;
}