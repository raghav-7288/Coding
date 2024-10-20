/*
Problem Statement
Maximum Sum Paths in a Grid
You are given a square grid of size 𝑛 × 𝑛. Each cell in the grid contains either:

A digit between '0' and '9', representing its value.
An obstacle denoted by 'x', which blocks the path.
Special Conditions:

The starting cell at the top-left corner (0, 0) and the ending cell at the bottom-right corner (𝑛−1, 𝑛−1) are always passable. Regardless of their original values in the grid, they are treated as if they contain the digit '0'.
Movement Rules:

From any given cell (𝑖, 𝑗), you can move to one of the following three adjacent cells:

Right: (𝑖, 𝑗 + 1)
Down: (𝑖 + 1, 𝑗)
Diagonally Down-Right: (𝑖 + 1, 𝑗 + 1)
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9 + 7;

pair<int, int> solve(int r, int c, int n, vector<vector<char>> &grid, vector<vector<pair<int, int>>> &dp)
{
    if (r < 0 || r >= n || c < 0 || c >= n || grid[r][c] == 'x')
        return {-1, 0};
    if (r == n - 1 && c == n - 1)
        return {0, 1};
    if (dp[r][c].first != -1)
        return dp[r][c];
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {1, 1}};
    int curMax = -1, curPath = 0;
    for (auto d : dir)
    {
        auto [sum, cnt] = solve(r + d.first, c + d.second, n, grid, dp);
        if (sum == -1)
            continue;
        if (sum + grid[r][c] - '0' > curMax)
        {
            curMax = sum + grid[r][c] - '0';
            curPath = cnt;
        }
        else if (sum + grid[r][c] - '0' == curMax)
        {
            curPath += cnt;
        }
    }
    return dp[r][c] = {curMax, curPath};
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
        vector<vector<char>> grid(n, vector<char>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
            }
        }
        grid[0][0] = '0';
        grid[n - 1][n - 1] = '0';
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {-1, 0}));
        auto [s, c] = solve(0, 0, n, grid, dp);
        cout << s << " " << c << endl;
    }
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

pair<int, int> solve(vector<vector<int>> &grid, int n)
{
    vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {0, 0}));
    dp[0][0] = {grid[0][0], 1};
    for (int i = 1; i < n; i++)
    {
        if (grid[0][i] != INT_MIN)
        {
            dp[0][i].first = dp[0][i - 1].first + grid[0][i];
            dp[0][i].second = dp[0][i - 1].second;
        }
        else
            dp[0][i] = {INT_MIN, 0};
    }

    for (int i = 1; i < n; i++)
    {
        if (grid[i][0] != INT_MIN)
        {
            dp[i][0].first = dp[i - 1][0].first + grid[i][0];
            dp[i][0].second = dp[i - 1][0].second;
        }
        else
            dp[i][0] = {INT_MIN, 0};
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (grid[i][j] == INT_MIN)
                dp[i][j] = {INT_MIN, 0};
            else
            {
                int maxi = max({dp[i - 1][j].first, dp[i][j - 1].first, dp[i - 1][j - 1].first});
                cout << maxi << endl;
                int total_path = 0;
                if (dp[i - 1][j].first == maxi)
                    total_path += dp[i - 1][j].second;
                if (dp[i - 1][j - 1].first == maxi)
                    total_path += dp[i - 1][j - 1].second;
                if (dp[i][j - 1].first == maxi)
                    total_path += dp[i][j - 1].second;
                dp[i][j] = {maxi + grid[i][j], total_path};
            }
        }
    }

    return dp[n - 1][n - 1];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                char ch;
                cin >> ch;
                if (ch == 'x')
                    grid[i][j] = INT_MIN;
                else
                    grid[i][j] = ch - '0';
            }
        }

        pair<int, int> res = solve(grid, n);
        cout << res.first << " " << res.second << endl;
    }

    return 0;
}
*/