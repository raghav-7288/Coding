#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9 + 7;
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
        int n, m;
        cin >> m >> n;
        vector<vector<int>> grid(n, vector<int>(m)), vis(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        int r, c;
        cin >> r >> c;
        int cx[4] = {-1, 0, 1, 0}, cy[4] = {0, 1, 0, -1};
        queue<pair<int, pair<int, int>>> q;
        q.push({1, {r, c}});
        vis[r][c] = 1;
        int ans = -1;
        while (!q.empty())
        {
            auto [d, rc] = q.front();
            q.pop();
            // if (rc.first == 0)
            ans = d;
            for (int i = 0; i < 4; i++)
            {
                int nr = rc.first + cx[i], nc = rc.second + cy[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc])
                {
                    q.push({d + 1, {nr, nc}});
                    vis[nr][nc] = 1;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}