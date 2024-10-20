/*
There is a mobile piece and a stationary piece on the N×M chessboard.
The available moves of the mobile piece are the same as set out in the image below.
You need to capture the stationary piece by moving the mobile piece with the minimum amount of moves.

Write a program to find out the minimum number moves to catch a piece.

[Input]
Several test cases can be included in the inputs. T, the number of cases is given in the first row of the
inputs. After that, the test cases as many as T (T ≤ 20) are given in a row.
N, the numbers of the rows and M, the number of columns of the chessboard are given in the first row of
each test case.
R & C is the location information of the attacking piece and S & K is the location of the defending pieces
and are given in the row at the second line. However, the location of the uppermost end of the left end
is (1, 1)

[Output]
For each test case, you should print "Case #T" in the first line where T means the case number.

For each test case, you should output the minimum number of movements to catch a defending piece at the
first line of each test case. If not moveable, output equals ‘-1’.

[I/O Example]

Input
2
9 9
3 5 2 8
20 20
2 3 7 9

Output
Case #1
2
Case #2
5
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9 + 7;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    vector<pair<int, int>> dir = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int mr, mc, sr, sc;
        cin >> mr >> mc >> sr >> sc;
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n + 1, vector<int>(m + 1));
        q.push({{mr, mc}, 0});
        vis[mr][mc] = 1;
        bool found = false;
        while (!q.empty())
        {
            auto [r, cursteps] = q.front();
            q.pop();
            if (r.first == sr && r.second == sc)
            {
                found = true;
                cout << cursteps << endl;
                break;
            }
            for (auto [cx, cy] : dir)
            {
                int nr = r.first + cx, nc = r.second + cy;
                if (nr >= 1 && nr <= n && nc >= 1 && nc <= n && !vis[nr][nc])
                {
                    q.push({{nr, nc}, cursteps + 1});
                    vis[nr][nc] = 1;
                }
            }
        }
        if (!found)
            cout << -1 << endl;
    }
    return 0;
}