// #include <bits/stdc++.h>
// using namespace std;
// int minCost(vector<int> &heights, vector<int> &cost)
// {
//     int n = heights.size();
//     vector<vector<long long>> dp(n, vector<long long>(3, LONG_LONG_MAX));
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

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Memoization map: key is pair of (index, previous adjusted height), value is minimal cost
map<pair<int, int>, long long> memo;

long long dp(int i, int prev_height, const vector<int> &heights, const vector<int> &cost)
{
    if (i == heights.size())
    {
        return 0;
    }

    // Memoization check
    auto key = make_pair(i, prev_height);
    if (memo.find(key) != memo.end())
    {
        return memo[key];
    }

    long long min_cost = LLONG_MAX;

    // Try increasing current height by delta = 0, 1, 2
    for (int delta = 0; delta <= 2; ++delta)
    {
        int adjusted_height = heights[i] + delta;

        // Ensure adjusted height is not equal to previous adjusted height
        if (adjusted_height != prev_height)
        {
            long long current_cost = delta * cost[i];
            long long total_cost = current_cost + dp(i + 1, adjusted_height, heights, cost);
            min_cost = min(min_cost, total_cost);
        }
    }
    memo[key] = min_cost;
    return min_cost;
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

    memo.clear(); // Clear memoization map before computation

    long long result = dp(0, -1, heights, cost);

    cout << "Minimum cost: " << result << endl; // Output should be 2

    return 0;
}
