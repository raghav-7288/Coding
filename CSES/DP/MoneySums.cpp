#include <bits/stdc++.h>
using namespace std;
// void ms(int i, int cs, int n, vector<int> &coins, set<int> &st)
// {
//     if (i == n)
//     {
//         st.insert(cs);
//         return;
//     }
//     ms(i + 1, cs, n, coins, st);
//     ms(i + 1, cs + coins[i], n, coins, st);
// }
// void solve(int n, vector<int> &coins)
// {
//     set<int> st;
//     ms(0, 0, n, coins, st);
//     cout << st.size() - 1 << endl;
//     for (auto s : st)
//         if (s)
//             cout << s << " ";
// }
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, maxi = 1e5;
    cin >> n;
    vector<int> dp(maxi + 1);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        for (int j = maxi - a; j >= 0; j--)
        {
            if (dp[j])
            {
                dp[j + a] = 1;
            }
        }
    }
    cout << accumulate(dp.begin(), dp.end(), -1) << endl;
    for (int j = 1; j <= maxi; j++)
    {
        if (dp[j])
            cout << j << " ";
    }
    // solve(n, coins);
    return 0;
}