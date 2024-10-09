#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    long long n;
    cin >> n;
    while (n != 1)
    {
        cout << n << " ";
        if (n & 1)
            n = n * 3 + 1;
        else
            n /= 2;
    }
    cout << 1;
    return 0;
}