#include <bits/stdc++.h>
using namespace std;
// int solve(int r, int c, int s, int n, string &path, string cur, map<char, pair<int, int>> &mp)
// {
//     if (r < 0 || r >= n || c < 0 || c >= n || s > n * n - 1)
//         return 0;
//     if (r == n - 1 && c == 0 && s == n * n - 1)
//     {
//         cout << cur << endl;
//         return 1;
//     }
//     if (path[s] != '?')
//     {
//         return solve(r + mp[path[s]].first, c + mp[path[s]].second, s + 1, n, path, cur + path[s], mp);
//     }
//     int ans = 0;
//     for (auto m : mp)
//     {
//         ans += solve(r + m.second.first, c + m.second.second, s + 1, n, path, cur + m.first, mp);
//     }
//     return ans;
// }
const int N = 7;
int ans;
string c;
bool vis[N + 1][N + 1];
bool inbounds(int x, int y)
{
    return 1 <= x && x <= N && 1 <= y && y <= N;
}
void dfs(int x, int y, int i)
{
    if (i == N * N - 1 || (x == N && y == 1))
    {
        ans += (i == N * N - 1 && (x == N && y == 1));
        return;
    }
    // if cannot move U and D but can move L AND R
    if ((!inbounds(x + 1, y) || vis[x + 1][y]) && (!inbounds(x - 1, y) || vis[x - 1][y]))
        if (inbounds(x, y - 1) && !vis[x][y - 1] && inbounds(x, y + 1) && !vis[x][y + 1])
            return;
    // if cannot move L and R but can move U AND D
    if ((!inbounds(x, y + 1) || vis[x][y + 1]) && (!inbounds(x, y - 1) || vis[x][y - 1]))
        if (inbounds(x + 1, y) && !vis[x + 1][y] && inbounds(x - 1, y) && !vis[x - 1][y])
            return;

    vis[x][y] = true;
    if (c[i] == 'D' || c[i] == '?')
        if (inbounds(x + 1, y) && !vis[x + 1][y])
            dfs(x + 1, y, i + 1);
    if (c[i] == 'U' || c[i] == '?')
        if (inbounds(x - 1, y) && !vis[x - 1][y])
            dfs(x - 1, y, i + 1);
    if (c[i] == 'R' || c[i] == '?')
        if (inbounds(x, y + 1) && !vis[x][y + 1])
            dfs(x, y + 1, i + 1);
    if (c[i] == 'L' || c[i] == '?')
        if (inbounds(x, y - 1) && !vis[x][y - 1])
            dfs(x, y - 1, i + 1);
    vis[x][y] = false;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    cin >> c;
    dfs(1, 1, 0);
    cout << ans;
    return 0;
}