#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    int ans = 0, j = 0, i = 1;
    for (; i < s.length(); i++)
    {
        if (s[i] != s[j])
        {
            ans = max(ans, i - j);
            j = i;
        }
    }
    ans = max(ans, i - j);
    cout << ans;
    return 0;
}
// ATTCGGGA