#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif

    int n, m, si, sj, ei, ej;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                si = i;
                sj = j;
            }
            if (grid[i][j] == 'B')
            {
                ei = i;
                ej = j;
            }
        }
    }

    map<char, pair<int, int>> mp;
    mp['U'] = {-1, 0};
    mp['D'] = {1, 0};
    mp['L'] = {0, -1};
    mp['R'] = {0, 1};

    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = 1;

    vector<vector<char>> dir(n, vector<char>(m));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));

    bool found = false;
    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();

        if (r == ei && c == ej)
        {
            found = true;
            break;
        }

        for (auto _m : mp)
        {
            int nr = r + _m.second.first, nc = c + _m.second.second;
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != '#' && !vis[nr][nc])
            {
                vis[nr][nc] = 1;
                q.push({nr, nc});
                parent[nr][nc] = {r, c};
                dir[nr][nc] = _m.first;
            }
        }
    }

    if (found)
    {
        string path = "";
        int r = ei, c = ej;
        while (!(r == si && c == sj))
        {
            path += dir[r][c];
            auto [pr, pc] = parent[r][c];
            r = pr;
            c = pc;
        }
        reverse(path.begin(), path.end());
        cout << "YES\n"
             << path.length() << "\n"
             << path;
    }
    else
    {
        cout << "NO";
    }
    return 0;
}
