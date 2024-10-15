#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll ans = 1e18;
void solve(int i, int n, ll cur, ll s, vector<ll> &w)
{
    if (i == n)
    {
        ans = min(ans, abs(s - 2 * cur));
        return;
    }
    solve(i + 1, n, cur + w[i], s, w);
    solve(i + 1, n, cur, s, w);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<ll> w(n);
    for (auto &x : w)
        cin >> x;
    ll sum = accumulate(w.begin(), w.end(), 0LL);
    solve(0, n, 0, sum, w);
    cout << ans;
    return 0;
}