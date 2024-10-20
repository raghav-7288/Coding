#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9 + 7;
void solve(int &ans, int r, int c, int power, int magic, int score, vector<vector<int>> &grid)
{
    ans = max(ans, score);
    if (r == 0)
    {
        ans = max(ans, score);
        return;
    }
    for (int i = -1; i <= 1; i++)
    {
        int nr = r - 1, nc = c + i;
        if (nr < 0 || nc < 0 || nc >= 5)
            continue;
        if (grid[nr][nc] == '2')
        {
            if (magic)
                solve(ans, nr, nc, power + 5, magic - 1, score, grid);
            if (score > 0)
                solve(ans, nr, nc, power - 1, magic, score - 1, grid);
            if (power > 0)
                solve(ans, nr, nc, power - 1, 0, score, grid);
            if (score == 0 && power <= 0 && magic == 0)
            {
                ans = max(ans, score);
                return;
            }
        }
        if (grid[nr][nc] == 1)
            solve(ans, nr, nc, power - 1, magic, score + 1, grid);
        if (grid[nr][nc] == 0)
            solve(ans, nr, nc, power - 1, magic, score, grid);
    }
}
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
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(5));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cin >> grid[i][j];
            }
        }
        int ans = -1;
        solve(ans, n, 2, 0, 1, 0, grid);
        if (ans == 0)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}