#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        if ((a + b) % 3 || a > 2 * b || b > 2 * a)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}