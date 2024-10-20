#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9 + 7;
void solve(int &ans, int r, int c, int power, int magic, int score, vector<vector<int>> &grid)
{
    ans = max(ans, score);
    if (r == 0)
    {
        ans = max(ans, score);
        return;
    }
    for (int i = -1; i <= 1; i++)
    {
        int nr = r - 1, nc = c + i;
        if (nr < 0 || nc < 0 || nc >= 5)
            continue;
        if (grid[nr][nc] == '2')
        {
            if (magic)
                solve(ans, nr, nc, power + 5, magic - 1, score, grid);
            if (score > 0)
                solve(ans, nr, nc, power - 1, magic, score - 1, grid);
            if (power > 0)
                solve(ans, nr, nc, power - 1, 0, score, grid);
            if (score == 0 && power <= 0 && magic == 0)
            {
                ans = max(ans, score);
                return;
            }
        }
        if (grid[nr][nc] == 1)
            solve(ans, nr, nc, power - 1, magic, score + 1, grid);
        if (grid[nr][nc] == 0)
            solve(ans, nr, nc, power - 1, magic, score, grid);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(5));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cin >> grid[i][j];
            }
        }
        int ans = -1;
        solve(ans, n, 2, 0, 1, 0, grid);
        if (ans == 0)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
void updateMatrix(int row,char ** matrix){
    if(row<0){
        return;
    }
    int upLimit=max(0,row-4);
    for(int i=row;i>=upLimit;i--){
        for(int j=0;j<=4;j++){
            if(matrix[i][j]=='2'){
                matrix[i][j]='0';
            }
        }
    }
}
int findMaxPoints(int row,int col,int bombs,char ** matrix){
    if(row<=0 || col<0 || col>=5){
        return 0;
    }
    int answer=0;
    if(row>0 && matrix[row-1][col]!='2'){
        answer=max(answer,(matrix[row-1][col]=='1'?1:0)+findMaxPoints(row-1,col,bombs,matrix));
    }
    if(col>0 && row>0 && matrix[row-1][col-1]!='2'){
        answer=max(answer,(matrix[row-1][col-1]=='1'?1:0)+findMaxPoints(row-1,col-1,bombs,matrix));
    }
    if(col<4 && row>0 && matrix[row-1][col+1]!='2'){
        answer=max(answer,(matrix[row-1][col+1]=='1'?1:0)+findMaxPoints(row-1,col+1,bombs,matrix));
    }

    if(answer==0 && bombs>0){
        updateMatrix(row-1,matrix);
        answer=findMaxPoints(row,col,bombs-1,matrix);
    }

    return answer;
}
int main(){
    int t, row;
    cin >> t;
    int tNo = 0;
    while(t--){
        cin >> row;
        char ** matrix=new char*[row + 2];
        for(int i=0; i<row; i++){
            matrix[i]=new char[5];
            for(int j=0;j<5;j++){
                cin>>matrix[i][j];
            }
        }
        tNo++;
        cout<< "#" << tNo << " : " << findMaxPoints(row,2,1,matrix) << endl;
    }
    return 0;
}
*/