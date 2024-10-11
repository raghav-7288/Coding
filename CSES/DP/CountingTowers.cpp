/*
dp[i][1] = 2*dp[i-1][1] +dp[i-1][0]
=>  2*ways because we can either extend the current level to one level down or keep another new tile +
    1*ways because we can only keep another new tile and cannot extend the current level downwards
dp[i][0] = dp[i-1][1]+ 4*dp[i-1][0]
=>  1*ways because we can only keep another new set of tiles and cannot extend the current level +
    4*ways because we can either keep a new tile, or extend both the sides together or extend a single side at one time(left or right side, so intotal 4 ways
*/

#include <bits/stdc++.h>
using namespace std;

#define f(i, a, b) for (int i = a; i < b; i++)
#define modm 1000000007
#define ll long long
const int N = 1000005;
ll dp[N][2];
int main()
{
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= N; i++)
    {
        dp[i][1] = (2 * (dp[i - 1][1] % modm)) % modm + (dp[i - 1][0] % modm);
        dp[i][0] = (dp[i - 1][1] % modm) + (4 * (dp[i - 1][0] % modm)) % modm;
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << (dp[n][0] % modm + dp[n][1] % modm) % modm << "\n";
    }
    return 0;
}