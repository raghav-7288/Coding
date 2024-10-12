#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, int> mp;
int solve(int n, int k)
{
    if (mp[{n, k}])
        return mp[{n, k}];
    if (n == 1)
        return mp[{n, k}] = 1;
    if (2 * k <= n)
        return mp[{n, k}] = 2 * k;
    int _n = (n / 2) + (n & 1), _k = k - n / 2;
    if (n & 1)
    {
        return mp[{n, k}] = (2 * solve(_n, _k) - 3 + n + 1) % (n + 1);
    }
    return mp[{n, k}] = 2 * solve(_n, _k) - 1;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int n, k;
        cin >> n >> k;
        cout << solve(n, k) << endl;
    }
    return 0;
}