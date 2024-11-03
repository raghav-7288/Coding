#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll mod = 1e9 + 7;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, ai, aj;
    cin >> n >> m;
    vector<vector<char>> grid(n + 1, vector<char>(m + 1)), dir(n + 1, vector<char>(m + 1));
    vector<vector<int>> distM(n + 1, vector<int>(m + 1, 1e9)), distA(n + 1, vector<int>(m + 1, 1e9));
    vector<vector<pair<int, int>>> parent(n + 1, vector<pair<int, int>>(m + 1));
    queue<pair<int, int>> q;
    vector<char> d = {'U', 'R', 'D', 'L'};
    int cx[4] = {-1, 0, 1, 0}, cy[4] = {0, 1, 0, -1};
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'M')
            {
                q.push({i, j});
                distM[i][j] = 0;
            }
            else if (grid[i][j] == 'A')
            {
                ai = i;
                aj = j;
            }
        }
    }
    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int nr = r + cx[k], nc = c + cy[k];
            if (nr >= 1 && nr <= n && nc >= 1 && nc <= m && grid[nr][nc] != '#' && distM[nr][nc] == 1e9)
            {
                distM[nr][nc] = 1 + distM[r][c];
                q.push({nr, nc});
            }
        }
    }
    q.push({ai, aj});
    distA[ai][aj] = 0;
    parent[ai][aj] = {-1, -1};
    bool found = false;
    int ei, ej;
    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();
        if (r == 1 || r == n || c == 1 || c == m)
        {
            ei = r;
            ej = c;
            found = true;
            break;
        }
        for (int k = 0; k < 4; k++)
        {
            int nr = r + cx[k], nc = c + cy[k];
            if (nr >= 1 && nr <= n && nc >= 1 && nc <= m && grid[nr][nc] != '#' && distA[nr][nc] == 1e9 && distA[r][c] + 1 < distM[nr][nc])
            {
                distA[nr][nc] = 1 + distA[r][c];
                q.push({nr, nc});
                parent[nr][nc] = {r, c};
                dir[nr][nc] = d[k];
            }
        }
    }
    if (found)
    {
        string path = "";
        while (!(ei == ai && ej == aj))
        {
            path += dir[ei][ej];
            auto [ni, nj] = parent[ei][ej];
            ei = ni;
            ej = nj;
        }
        reverse(path.begin(), path.end());
        cout << "YES\n"
             << path.size() << "\n"
             << path;
    }
    else
    {
        cout << "NO\n";
    }
    return 0;
}