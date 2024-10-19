#include <bits/stdc++.h>
using namespace std;
int res = 0;
void solve(int ind, int r, int c, int n, int m, int &co, string &s, vector<vector<int>> &vis, vector<vector<char>> &grid)
{
    if (r < 0 || r >= n || c < 0 || c >= m || vis[r][c] || grid[r][c] != s[ind])
    {
        return;
    }
    if (ind == s.length() - 1)
    {
        co++;
        res = max(res, co);
    }
    vis[r][c] = 1;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            int nr = r + i, nc = c + j;
            solve((ind + 1) % s.length(), nr, nc, n, m, co, s, vis, grid);
        }
    }
    vis[r][c] = 0;
    if (ind == s.length() - 1)
        co--;
}

int main()
{
    // string s = "HARSH";
    // vector<vector<char>> grid = {
    //     {'H', 'R', 'R', 'B', 'H', 'C'},
    //     {'A', 'A', 'S', 'S', 'H', 'D'},
    //     {'H', 'R', 'H', 'K', 'A', 'E'},
    //     {'H', 'S', 'A', 'L', 'R', 'F'},
    //     {'N', 'P', 'H', 'H', 'S', 'G'},
    //     {'O', 'Q', 'N', 'O', 'P', 'P'}};

    // string s = "IRAGE";
    // vector<vector<char>> grid = {
    //     {'I', 'R', 'I', 'R', 'E'},
    //     {'A', 'E', 'A', 'G', 'I'},
    //     {'G', 'A', 'G', 'R', 'R'},
    //     {'E', 'R', 'A', 'I', 'A'},
    //     {'I', 'G', 'E', 'G', 'E'}};

    string s = "ABCB";
    vector<vector<char>> grid = {
        {'A', 'B', 'C', 'A', 'B', 'C', 'A', 'B', 'C', 'A'},
        {'B', 'C', 'A', 'B', 'C', 'A', 'B', 'C', 'A', 'B'},
        {'C', 'A', 'B', 'C', 'A', 'B', 'C', 'A', 'B', 'C'},
        {'A', 'B', 'C', 'A', 'B', 'C', 'A', 'B', 'C', 'A'},
        {'B', 'C', 'A', 'B', 'C', 'A', 'B', 'C', 'A', 'B'},
        {'C', 'A', 'B', 'C', 'A', 'B', 'C', 'A', 'B', 'C'},
        {'A', 'B', 'C', 'A', 'B', 'C', 'A', 'B', 'C', 'A'},
        {'B', 'C', 'A', 'B', 'C', 'A', 'B', 'C', 'A', 'B'},
        {'C', 'A', 'B', 'C', 'A', 'B', 'C', 'A', 'B', 'C'},
        {'A', 'B', 'C', 'A', 'B', 'C', 'A', 'B', 'C', 'A'}};

    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int co = 0;
    solve(0, 0, 0, n, m, co, s, vis, grid);
    cout << res;
    return 0;
}

/*
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(int i, int j, int ind, string cur, string &s, vector<vector<char>>& mat, vector<vector<int>>& vis){
    vis[i][j]=1;
    if(cur==s){
        return 1+solve(i, j, 0, "", s, mat, vis);
    }
    int maxi=0;
    for(int dr=-1;dr<=1;dr++){
        for(int dc=-1; dc<=1;dc++){
            int nr=i+dr;
            int nc=j+dc;
            if(nr>=0 && nr<mat.size() && nc>=0 && nc<mat[0].size() && vis[nr][nc]==0 && mat[nr][nc]==s[ind]){
                int tmp=0;
                tmp=solve(nr, nc, ind+1, cur+s[ind], s, mat, vis);
                maxi=max(maxi, tmp);
            }
        }

    }
    vis[i][j]=0;
    return maxi;
}
int main() {
    int n, m;
    cin>>n>>m;
    string s;
    cin>>s;
    vector<vector<char>> mat(n, vector<char>(m));
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    string tmp=s.substr(0,1);
    cout<<solve(0, 0, 1, tmp, s, mat, vis);
    return 0;
}
*/