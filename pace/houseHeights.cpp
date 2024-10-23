#include <bits/stdc++.h>
using namespace std;
#define ll long long
// int minCost(vector<int> &heights, vector<int> &cost)
// {
//     int n = heights.size();
//     vector<vector<ll>> dp(n, vector<ll>(3, LONG_LONG_MAX));
//     dp[0][0] = 0;
//     dp[0][1] = cost[0];
//     dp[0][2] = 2 * cost[0];
//     for (int i = 1; i < n; ++i)
//     {
//         for (int j = 0; j < 3; ++j)
//         {
//             for (int k = 0; k < 3; ++k)
//             {
//                 if (heights[i - 1] + k != heights[i] + j)
//                 {
//                     dp[i][j] = min(dp[i][j], dp[i - 1][k] + j * cost[i]);
//                 }
//             }
//         }
//     }
//     return min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
// }
// int main()
// {
// #ifndef ONLINE_JUDGE
//     freopen("../input.txt", "r", stdin);
//     freopen("../output.txt", "w", stdout);
// #endif
//     vector<int> heights = {2, 2, 2, 3, 3, 3, 4, 5};
//     vector<int> cost = {1, 100, 3, 4, 100, 6, 7, 8};
//     int result = minCost(heights, cost);
//     cout << "Minimum cost: " << result << endl;
//     return 0;
// }

map<pair<int, int>, ll> memo;
ll solve(int i, int prev_height, const vector<int> &heights, const vector<int> &cost)
{
    if (i == heights.size())
    {
        return 0;
    }
    auto key = make_pair(i, prev_height);
    if (memo.find(key) != memo.end())
    {
        return memo[key];
    }
    ll min_cost = LLONG_MAX;
    for (int delta = 0; delta <= 2; ++delta)
    {
        int adjusted_height = heights[i] + delta;
        if (adjusted_height != prev_height)
        {
            ll total_cost = delta * cost[i] + solve(i + 1, adjusted_height, heights, cost);
            min_cost = min(min_cost, total_cost);
        }
    }
    return memo[key] = min_cost;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n = 3;
    vector<int> heights = {2, 2, 2, 3, 3, 3, 4, 5};
    vector<int> cost = {1, 100, 3, 4, 100, 6, 7, 8};
    memo.clear();
    cout << solve(0, -1, heights, cost);
    return 0;
}
