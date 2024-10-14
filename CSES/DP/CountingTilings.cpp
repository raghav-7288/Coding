#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9 + 7;

int n, m;
unordered_map<int, ll> dp[1001]; // Adjust size according to constraints

ll solve(int row, int state)
{
    if (row == n)
        return state == 0 ? 1 : 0;

    if (dp[row].count(state))
        return dp[row][state];

    ll ans = 0;

    // Generate all possible states for the current row
    function<void(int, int, int)> dfs = [&](int col, int cur_state, int next_state)
    {
        if (col == m)
        {
            ans = (ans + solve(row + 1, next_state)) % MOD;
            return;
        }

        if ((cur_state & (1 << col)) != 0) // Cell is already filled
        {
            dfs(col + 1, cur_state, next_state);
        }
        else
        {
            // Place vertical tile
            if (row + 1 < n)
            {
                dfs(col + 1, cur_state, next_state | (1 << col));
            }
            // Place horizontal tile
            if (col + 1 < m && (cur_state & (1 << (col + 1))) == 0)
            {
                dfs(col + 2, cur_state, next_state);
            }
        }
    };

    dfs(0, state, 0);
    return dp[row][state] = ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> n >> m;

    if (n < m)
        swap(n, m); // Ensure that n >= m for optimization

    cout << solve(0, 0) << endl;
    return 0;
}
