#include <bits/stdc++.h>
using namespace std;
bool isValid(int row, int col, char c, vector<vector<char>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        if (board[row][i] == c) // row
            return false;
        if (board[i][col] == c) // col
            return false;
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) // 3x3
            return false;
    }
    return true;
}
bool solve(vector<vector<char>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        { // find if any empty position
            if (board[i][j] == '.')
            { // check for every char at ampty pos
                for (char c = '1'; c <= '9'; c++)
                { // if no char gives valid board return true
                    if (isValid(i, j, c, board))
                    {
                        board[i][j] = c; // place the char if isValid
                        if (solve(board))
                        {
                            return true;
                        }
                        else
                        { // backTrack if after placing the char the board becomes invalid
                            board[i][j] = '.';
                        }
                    }
                } // if at any call we have an empty space but all chars there are invalid
                return false;
            }
        }
    }
    // if no empty pos return true
    return true;
}
void solveSudoku(vector<vector<char>> &board)
{ // recursive solve
    solve(board);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}