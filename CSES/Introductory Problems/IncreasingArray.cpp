#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, maxi = 0;
    long long ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (maxi)
        {
            if (a < maxi)
                ans += (maxi - a);
        }
        maxi = max(a, maxi);
    }
    cout << ans;
    return 0;
}