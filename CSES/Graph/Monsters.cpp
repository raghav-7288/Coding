#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, m, ai, aj;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    map<char, pair<int, int>> mp;
    mp['U'] = {-1, 0};
    mp['D'] = {1, 0};
    mp['L'] = {0, -1};
    mp['R'] = {0, 1};

    vector<vector<int>> distM(n, vector<int>(m, INT_MAX));
    vector<vector<int>> distA(n, vector<int>(m, INT_MAX));
    vector<vector<char>> dir(n, vector<char>(m));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                ai = i;
                aj = j;
            }
            if (grid[i][j] == 'M')
            {
                q.push({i, j});
                distM[i][j] = 0;
            }
        }
    }

    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();
        for (auto _m : mp)
        {
            int nr = r + _m.second.first, nc = c + _m.second.second;
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != '#' && distM[nr][nc] == INT_MAX)
            {
                distM[nr][nc] = distM[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }

    q.push({ai, aj});
    distA[ai][aj] = 0;
    parent[ai][aj] = {-1, -1};

    bool found = false;
    int ei, ej;

    if (ai == 0 || aj == 0 || ai == n - 1 || aj == m - 1)
    {
        found = true;
        ei = ai;
        ej = aj;
    }
    else
    {
        while (!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();

            if (r == 0 || c == 0 || r == n - 1 || c == m - 1)
            {
                ei = r;
                ej = c;
                found = true;
                break;
            }

            for (auto _m : mp)
            {
                int nr = r + _m.second.first, nc = c + _m.second.second;
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != '#' && distA[nr][nc] == INT_MAX)
                {
                    if (distA[r][c] + 1 < distM[nr][nc])
                    {
                        distA[nr][nc] = distA[r][c] + 1;
                        q.push({nr, nc});
                        parent[nr][nc] = {r, c};
                        dir[nr][nc] = _m.first;
                    }
                }
            }
        }
    }

    if (found)
    {
        string path = "";
        int r = ei, c = ej;
        while (!(r == ai && c == aj))
        {
            path += dir[r][c];
            auto [pr, pc] = parent[r][c];
            r = pr;
            c = pc;
        }
        reverse(path.begin(), path.end());
        cout << "YES\n";
        cout << path.length() << endl;
        cout << path << endl;
    }
    else
    {
        cout << "NO\n";
    }
    return 0;
}
