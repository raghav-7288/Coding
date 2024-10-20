/*
https://www.youtube.com/watch?v=IFNibRVgFBo - Tushar Roy

Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums.
You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins.
Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.
Input: [3,1,5,8]
Output: 167
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9 + 7;
int solve(int i, int j, vector<int> &points, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;
    // if (i == j)
    //     return points[i];
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = 0;
    for (int k = i; k <= j; k++)
    {
        ans = max(ans, points[i - 1] * points[k] * points[j + 1] + solve(i, k - 1, points, dp) + solve(k + 1, j, points, dp));
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