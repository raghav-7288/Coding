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
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int d;
    cin >> d;
    d %= n;
    // change d for RR
    d = n - d;
    // reverse(a,b) range-> [a,b)
    reverse(a, a + d);
    reverse(a + d, a + n);
    reverse(a, a + n);
    for (auto x : a)
    {
        cout << x << " ";
    }
    return 0;
}