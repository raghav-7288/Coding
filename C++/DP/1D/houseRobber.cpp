/*
213.You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed.
All houses at this place are arranged in a circle.
That means the first house is the neighbor of the last one.
Meanwhile, adjacent houses have a security system connected,
and it will automatically contact the police if two adjacent
houses were broken into on the same night.
*/

#include <bits/stdc++.h>
using namespace std;
int solve(int index, int n, vector<int> &nums, vector<int> &dp)
{
    if (index >= n)
        return 0;
    if (dp[index] != -1)
        return dp[index];
    int rob = nums[index] + solve(index + 2, n, nums, dp);
    int notRob = solve(index + 1, n, nums, dp);
    return dp[index] = max(rob, notRob);
}
int rob(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];
    vector<int> dp(nums.size(), -1);
    int leave_1 = solve(1, nums.size(), nums, dp);
    fill(dp.begin(), dp.end(), -1);
    int leave_n = solve(0, nums.size() - 1, nums, dp);
    return max(leave_1, leave_n);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}