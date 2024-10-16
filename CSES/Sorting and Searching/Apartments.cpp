#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> r(n), s(m);
    for (auto &_r : r)
        cin >> _r;
    for (auto &_s : s)
        cin >> _s;
    sort(r.begin(), r.end(), greater<int>());
    sort(s.begin(), s.end(), greater<int>());
    int ans = 0, c = 0;
    for (int a = 0; a < m; a++)
    {
        if (abs(s[a] - r[c]) <= k)
        {
            ans++;
            c++;
        }
    }
    cout << ans;
    return 0;
}