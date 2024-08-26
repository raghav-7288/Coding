#include <bits/stdc++.h>
using namespace std;
// isSafe->O(3n)->>optimised using hashing
bool isSafe(int x, int y, int n, vector<string> &board)
{
    int nx = x;
    int ny = y;
    // upperDiag
    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 'Q')
            return false;
        x--;
        y--;
    }
    // lowerDiag
    x = nx;
    y = ny;
    while (x < n && y >= 0)
    {
        if (board[x][y] == 'Q')
            return false;
        x++;
        y--;
    }
    // leftColsOFSameRow
    x = nx;
    y = ny;
    while (y >= 0)
    {
        if (board[x][y] == 'Q')
            return false;
        y--;
    }
    return true;
}
// for every col call recursion and for each row
// check if safe to place queen
// backtrack
void solve(int col, int n, vector<string> &board, vector<vector<string>> &allPossBoards)
{
    if (col == n)
    {
        allPossBoards.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, n, board))
        {
            board[row][col] = 'Q';
            solve(col + 1, n, board, allPossBoards);
            board[row][col] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n, vector<vector<string>> &allPossBoards)
{
    vector<string> board(n);
    string str(n, '.');
    for (int i = 0; i < n; i++)
    {
        board[i] = str;
    }
    solve(0, n, board, allPossBoards);
    return allPossBoards;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        vector<vector<string>> allPossBoards;
        solveNQueens(i, allPossBoards);
        cout << allPossBoards.size() << endl;
    }
    // for (auto boards : allPossBoards)
    // {
    //     for (auto x : boards)
    //     {
    //         cout << x << endl;
    //     }
    //     cout << endl;
    // }

    return 0;
}