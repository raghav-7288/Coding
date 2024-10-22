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
        int n;
        ll x;
        cin >> n;
        bool even = true;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            even &= !(x & 1);
        }
        cout << (even ? "second\n" : "first\n");
    }
    return 0;
}