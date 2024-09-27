#include <bits/stdc++.h>
using namespace std;
int solve(int i, int n, vector<int> &nums, vector<int> &dp)
{
    if (i >= n)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int pick = nums[i] + solve(i + 2, n, nums, dp);
    int notpick = solve(i + 1, n, nums, dp);
    return dp[i] = max(pick, notpick);
}
int rob(int i, vector<int> &nums)
{
    vector<int> dp(nums.size(), -1);
    return solve(i, nums.size(), nums, dp);
}
int main()
{
    int n;
    cin >> n;
    vector<int> points(n);
    for (int i = 0; i < n; i++)
    {
        cin >> points[i];
    }
    int ans = -1;
    for (int i = 0; i < points.size(); i++)
    {
        ans = max(ans, rob(i, points));
    }
    cout << ans;
    return 0;
}