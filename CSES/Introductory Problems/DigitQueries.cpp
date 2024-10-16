#include <bits/stdc++.h>
using namespace std;
int solve(long long k)
{
    if (k < 10)
        return k;
    long long steps = 9, d = 1, cur = 0;
    while (k >= steps * d)
    {
        k -= steps * d;
        cur += steps;
        steps *= 10;
        d++;
    }
    cur += k / d;
    cur += (k % d ? 1 : 0);
    if (k % d == 0)
        return cur % 10;
    return to_string(cur)[k % d - 1] - '0';
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int q;
    cin >> q;
    while (q--)
    {
        long long k;
        cin >> k;
        cout << solve(k) << endl;
    }
    return 0;
}