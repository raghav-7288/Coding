/*
There is some intuition- to empty a pile a position k
, we will have to empty it all the way to position 1
, which means there are (k−1)
 copies of that pile which we have to empty.
So if k
 is odd, xor of k
 even number of times is 0
, so the odd positions don't create an effect, and hence we consider the even positions only.
*/
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
        ll n, u, x = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> u;
            if (i % 2)
                x ^= u;
        }
        if (x)
            cout << "first\n";
        else
            cout << "second\n";
    }
    return 0;
}