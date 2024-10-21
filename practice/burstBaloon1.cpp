/*
There are n balloons and n bullets and each balloon is assigned with a particular number (point).
Whenever a particular balloon is shot the no of points increases by
1.the multiplication of point assigned to balloon on left and that of right side.
2.point assigned to left if no right exists
3.point assigned to right if no left exists.
4.the point assigned to itself if no other balloon exists.

You have to output the maximum no of points possible.

Input
1 2 3 4

Output
20
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9 + 7;
int solve(int i, int j, vector<int> &points, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;
    if (i == j)
        return points[i];
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = 0;
    for (int k = i; k <= j; k++)
    {
        int p = points[k - 1] * points[k + 1];
        if (k == i)
            p = points[k + 1];
        else if (k == j)
            p = points[k - 1];
        ans = max(ans, p + solve(i, k - 1, points, dp) + solve(k + 1, j, points, dp));
    }
    return dp[i][j] = ans;
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
        vector<int> points(n);
        for (auto &p : points)
            cin >> p;
        points.push_back(1);
        points.insert(points.begin(), 1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
        cout << solve(1, n, points, dp) << endl;
    }

    return 0;
}