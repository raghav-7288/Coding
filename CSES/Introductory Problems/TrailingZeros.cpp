#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, ans = 0, p = 5;
    cin >> n;
    while (n / p)
    {
        ans += (n / p);
        p *= 5;
    }
    cout << ans;
    return 0;
}