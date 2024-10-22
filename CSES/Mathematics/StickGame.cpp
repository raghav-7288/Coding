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
    int n, k;
    cin >> n >> k;
    vector<int> moves(k), dp(n + 1);
    for (auto &m : moves)
        cin >> m;
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (i - moves[j] >= 0 && !dp[i - moves[j]])
            {
                dp[i] = 1;
            }
        }
        cout << ("LW")[dp[i]];
    }
    return 0;
}