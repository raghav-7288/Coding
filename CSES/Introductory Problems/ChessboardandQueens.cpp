#include <bits/stdc++.h>
using namespace std;
int n = 8;
long long ans = 0;
bool isOK(int r, int c, vector<vector<char>> &board)
{
    int _r = r - 1, _c = c - 1;
    while (_r >= 0 && _c >= 0)
    {
        if (board[_r][_c] == 'q')
            return false;
        _r--;
        _c--;
    }
    _r = r - 1;
    _c = c;
    while (_r >= 0)
    {
        if (board[_r][_c] == 'q')
            return false;
        _r--;
    }
    _r = r - 1;
    _c = c + 1;
    while (_r >= 0 && _c >= 0)
    {
        if (board[_r][_c] == 'q')
            return false;
        _r--;
        _c++;
    }
    return true;
}
void solve(int r, vector<vector<char>> &board)
{
    if (r == n)
    {
        ans++;
        return;
    }
    for (int c = 0; c < n; c++)
    {
        if (board[r][c] != '*' && isOK(r, c, board))
        {
            board[r][c] = 'q';
            solve(r + 1, board);
            board[r][c] = '.';
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    vector<vector<char>> board(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    solve(0, board);
    cout << ans;
    return 0;
}