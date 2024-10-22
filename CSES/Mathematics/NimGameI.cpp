/*
In normal play, the winning strategy is to finish every move with a nim-sum of 0.
This is always possible if the nim-sum is not zero before the move. If the nim-sum is zero,
then the next player will lose if the other player does not make a mistake.
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
        int n, u, x = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> u;
            x ^= u;
        }
        if (x)
            cout << "first\n";
        else
            cout << "second\n";
    }
    return 0;
}