#include <bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> &mat)
{
    for (auto x : mat)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
}
void transpose(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }
}
void rotate90(vector<vector<int>> &mat, int dir)
{
    transpose(mat);
    int r = mat.size();
    int c = mat[0].size();
    if (dir == 1) // clockwise->swap cols
    {
        for (int j = 0; j < c / 2; j++)
        {
            for (int i = 0; i < r; i++)
            {
                swap(mat[i][j], mat[i][c - j - 1]);
            }
        }
    }
    else // clockwise->swap rows
    {
        for (int i = 0; i < r / 2; i++)
        {
            for (int j = 0; j < c; j++)
            {
                swap(mat[i][j], mat[r - i - 1][j]);
            }
        }
    }
    print(mat);
}
void rotate90exceptCorners(vector<vector<int>> &mat, int dir)
{
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n = 3, m = 3;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    rotate90(mat, -1);
    // reverse(mat.begin(), mat.end());
    // print(mat);
    return 0;
}