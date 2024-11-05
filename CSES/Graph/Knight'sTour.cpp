#include <bits/stdc++.h>
using namespace std;

int n = 8;
vector<pair<int, int>> dir = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};
int countOnwardMoves(int r, int c, vector<vector<int>> &grid)
{
    int cnt = 0;
    for (auto [cr, cc] : dir)
    {
        int nr = r + cr, nc = c + cc;
        if (nr >= 0 && nr < n && nc >= 0 && nc < n && !grid[nr][nc])
        {
            cnt++;
        }
    }
    return cnt;
}
bool dfs(int r, int c, int s, vector<vector<int>> &grid)
{
    grid[r][c] = s;
    if (s == n * n)
    {
        return true;
    }
    vector<tuple<int, int, int>> moves;
    for (auto [cr, cc] : dir)
    {
        int nr = r + cr, nc = c + cc;
        if (nr >= 0 && nr < n && nc >= 0 && nc < n && !grid[nr][nc])
        {
            int cnt = countOnwardMoves(nr, nc, grid);
            moves.push_back(make_tuple(cnt, nr, nc));
        }
    }
    sort(moves.begin(), moves.end());
    for (auto [_, nextR, nextC] : moves)
    {
        if (dfs(nextR, nextC, s + 1, grid))
        {
            return true;
        }
    }
    grid[r][c] = 0;
    return false;
}
int main()
{
    int r, c;
    cin >> c >> r;
    vector<vector<int>> grid(n, vector<int>(n));

    if (dfs(r - 1, c - 1, 1, grid))
    {
        for (auto &row : grid)
        {
            for (auto cell : row)
                cout << setw(2) << cell << " ";
            cout << endl;
        }
    }
    else
    {
        cout << "No solution exists." << endl;
    }
    return 0;
}
