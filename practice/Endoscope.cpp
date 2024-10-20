/*
Company S has developed an industrial endoscope available to explore inner part of the decrepit water pipes. It is possible to explore the inner part of the pipes putting the endoscope in a certain part of the pipe. The endoscope can be moved in the pipe only. Meanwhile, when the pipes are connected, if the length of the endoscope is long enough to explore, then it can inspect the connected pipes. However, we cannot observe every pipe because the length of the endoscope is limited.

When the map of the ground water pipe, the location where the endoscope to out in, and the length of the endoscope is given, calculate the number of pipe which are available to explore. Length of endoscope means the range upto which endoscope can explore. There are seven kind of pipes, and description for each pipe are shown below:
When the map of the groundwater pipe, the location where the endoscope to out in, and the length of the endoscope is given, calculate the number of the pipe which are available to explore. Length of endoscope means the range up to which endoscope can explore.

Input
In the first line, T, the number of total test cases are given. From the second line, T test cases are given. In the first line of each test case, N, the height of the map of the groundwater pipes, M, the width, R, the vertical location of the water pipe where to put in the endoscope, C, the horizontal location of it, and the length of the endoscope L are given. In the following N lines, information about the map of the groundwater pipe is given. Each line has M numbers. Each number (from 1 to 7) means the type of water pipe for that point. 0 means there is no water pipe buried in that place.

Output
Print the respective answer for T test cases in total for T lines. The answer is the number of water pipes which is available to observe using the endoscope.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9 + 7;
// void dfs(int &ans, int r, int c, int n, int m, int l, vector<vector<int>> &vis, vector<vector<int>> &grid, map<int, vector<pair<int, int>>> &mp, map<pair<int, int>, pair<int, int>> &opposite)
// {
//     if (l <= 0)
//         return;
//     vis[r][c] = 1;
//     for (auto [cx, cy] : mp[grid[r][c]])
//     {
//         int nr = r + cx, nc = c + cy;
//         if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc])
//         {
//             auto op = opposite[{cx, cy}];
//             bool connected = false;
//             for (auto [_cx, _cy] : mp[grid[nr][nc]])
//             {
//                 if (_cx == op.first && _cy == op.second)
//                 {
//                     connected = true;
//                     break;
//                 }
//             }
//             if (connected)
//             {
//                 ans++;
//                 dfs(ans, nr, nc, n, m, l - 1, vis, grid, mp, opposite);
//             }
//         }
//     }
// }
int bfs(int r, int c, int len, vector<vector<int>> &grid, vector<vector<pair<int, int>>> &mp, map<pair<int, int>, pair<int, int>> opposite)
{
    int n = grid.size(), m = grid[0].size();
    queue<pair<int, pair<int, int>>> q;
    vector<vector<int>> vis(n, vector<int>(m));
    q.push({len - 1, {r, c}});
    vis[r][c] = 1;
    int ans = 1;
    while (!q.empty())
    {
        auto [l, rc] = q.front();
        q.pop();
        if (!l)
            continue;
        for (auto [cx, cy] : mp[grid[rc.first][rc.second]])
        {
            int nr = rc.first + cx, nc = rc.second + cy;
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc])
            {
                auto op = opposite[{cx, cy}];
                bool connected = false;
                for (auto [_cx, _cy] : mp[grid[nr][nc]])
                {
                    if (_cx == op.first && _cy == op.second)
                    {
                        connected = true;
                        break;
                    }
                }
                if (connected)
                {
                    ans++;
                    q.push({l - 1, {nr, nc}});
                    vis[nr][nc] = 1;
                }
            }
        }
    }
    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    vector<vector<pair<int, int>>> mp(8);
    mp[1] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    mp[2] = {{1, 0}, {-1, 0}};
    mp[3] = {{0, -1}, {0, 1}};
    mp[4] = {{-1, 0}, {0, 1}};
    mp[5] = {{1, 0}, {0, 1}};
    mp[6] = {{1, 0}, {0, -1}};
    mp[7] = {{-1, 0}, {0, -1}};

    map<pair<int, int>, pair<int, int>> opposite = {
        {{1, 0}, {-1, 0}},
        {{-1, 0}, {1, 0}},
        {{0, -1}, {0, 1}},
        {{0, 1}, {0, -1}}};

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, r, c, l;
        cin >> n >> m >> r >> c >> l;
        vector<vector<int>> grid(n, vector<int>(m)), vis(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        if (r < 0 || r >= n || c < 0 || c >= m || !grid[r][c])
        {
            cout << "0" << endl;
            continue;
        }
        // int ans = 1;
        // dfs(ans, r, c, n, m, l - 1, vis, grid, mp, opposite);
        // cout << ans << endl;

        cout << bfs(r, c, l, grid, mp, opposite) << endl;
    }
    return 0;
}