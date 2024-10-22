#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll mod = 1e9 + 7;
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
        int n, u, x = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> u;
            u %= 4; // only change form nim game 1 as now can remove 1 or 2 or 3 sticks
            x ^= u;
        }
        if (x)
            cout << "first\n";
        else
            cout << "second\n";
    }
    return 0;
}