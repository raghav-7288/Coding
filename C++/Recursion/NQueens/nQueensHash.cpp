#include <bits/stdc++.h>
using namespace std;
void solve(int col, int n, vector<string> &board, vector<vector<string>> &ans,
           vector<int> &leftRow, vector<int> &lowerDiag, vector<int> &upperDiag)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (!leftRow[row] && !lowerDiag[row + col] && !upperDiag[n - 1 + col - row])
        {
            leftRow[row] = 1;
            lowerDiag[row + col] = 1;
            upperDiag[n - 1 + col - row] = 1;
            board[row][col] = 'Q';
            solve(col + 1, n, board, ans, leftRow, lowerDiag, upperDiag);
            board[row][col] = '.';
            leftRow[row] = 0;
            lowerDiag[row + col] = 0;
            upperDiag[n - 1 + col - row] = 0;
        }
    }
}
vector<vector<string>> solveNQueens(int n, vector<vector<string>> &ans)
{
    vector<string> board(n);
    string str(n, '.');
    for (int i = 0; i < n; i++)
    {
        board[i] = str;
    }
    vector<int> leftRow(n);
    vector<int> lowerDiag(2 * n - 1);
    vector<int> upperDiag(2 * n - 1);
    solve(0, n, board, ans, leftRow, lowerDiag, upperDiag);
    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    // for (int i = 1; i <= n; i++)
    // {
    vector<vector<string>> allPossBoards;
    solveNQueens(n, allPossBoards);
    //     cout << allPossBoards.size() << endl;
    // }
    for (auto boards : allPossBoards)
    {
        for (auto x : boards)
        {
            cout << x << endl;
        }
        cout << endl;
    }

    return 0;
}